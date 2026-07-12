# ft_parse 

A lightweight, robust command-line interface (CLI) options parsing library designed for modular deployment. This guide details how to integrate `ft_parse` as a sub-module static library within your root build systems.

## Key Architecture Updates
* **Parameter Injection**: Unified option parsing infrastructure via direct structure injection into `ft_parse`.
* **Isolated Core Logic**: Complete decoupling of custom action triggers from the central option evaluation engine.
* **Standalone Archiver Pipeline**: Dedicated build rule optimized to generate target-agnostic libraries (`.a`) free of isolated `main` entrypoints.

---

## Technical Blueprint & Usage

### 1. Declaring Options & Initializing (`test.c`)

To define options, create an array of `struct parse_option` in your application. The first element can hold the general description, and the array must be terminated with a sentinel node `{0}`.

```c
#include <stddef.h>
#include "ft_parse.h"

int main(int ac, const char **av)
{
    // Define your custom CLI options layout
    const struct parse_option options[] = {
        {0, NULL, NULL, "send ICMP ECHO_REQUEST to network hosts", handle_base},
        {'v', "verbose", "Produce verbose output", NULL, handle_verbose},
        {'c', "count",   "Stop after sending NUMBER packets", "ping -c 5 google.com", handle_count},
        {'d', "debug",   "Enable debug mode with extra logs", "ping --debug", NULL},
        {'h', "help",    "Give this help list", "ping --help", handle_help},
        {0, NULL, NULL, NULL, NULL} // Array terminator
    };

    // Pass your layout configuration directly into the engine
    int result = ft_parse(ac, av, options);
    return (result);
}

```
## Integration Blueprint
### 2. Root Makefile Configuration
To link against the compiled library, your root Makefile must trigger the archiver pipeline in the submodule directory. Reference the pathing and synchronization configuration below:
```makefile
# Define submodule workspace variables
FT_PARSE_DIR = ft_parse
LIB_PARSE    = $(FT_PARSE_DIR)/ft_parse.a
INC_DIRS     = -I $(FT_PARSE_DIR)/include -I $(FT_PARSE_DIR)/src

$(NAME): $(OBJS)
	@$(MAKE) -C $(FT_PARSE_DIR) archiver
	@$(CC) $(CFLAGS) $(OBJS) $(LIB_PARSE) -o $@
	@echo "[SUCCESS] Root build complete: ./$(NAME) is ready."

```
> [!NOTE]
> Always use $(MAKE) -C instead of raw make keywords to safely pass down operational flags, environment variables, and job limits to target children workspaces.
> 
## Technical Evaluation and Diagnostics
### Compilation Verification
Executing the workspace compilation sequence natively synchronizes intermediate outputs and formats the dependency artifacts:
```sh
$ make
make[1]: Entering directory '/home/kyoulee/Documents/projects/kyoulee/ft_parse'
[CLEAN] Removed intermediate object files directory.
[SUCCESS] Production build standard sequence complete: ft_parse.a
make[1]: Leaving directory '/home/kyoulee/Documents/projects/kyoulee/ft_parse'
[SUCCESS] Root build complete: ./test_parser is ready.

```
### Runtime Behavior Testing
#### Standard Execution Sequence
When triggered with empty arguments, the target infrastructure securely runs the underlying parser interface:
```sh
$ ./test_parser 
ft_parse result code: 0

```
#### Valid Parameter Evaluation
Injecting standard registered short or long arguments executes internal structural handler macros seamlessly:
```sh
$ ./test_parser -v
option is verbose 
[test.c] found option: Verbose Mode On!
[test.c] option is : -v
ft_parse result code: 0

```
#### Invalid Parameter Interception & Formatting
If unmapped variables or illegal operational options are provided, the system overrides runtime traps, isolates error bubbles, dumps auto-generated dynamic usage instructions, and exits with non-zero integrity fault flags:
```sh
$ ./test_parser -x 
Usage
  test_parser [OPTION...]

DESCRIPTION
  Baseline infrastructure layer

Options
  -v, --verbose                Produce verbose output

----------------------------------------------------------
Report bugs to: <kyoulee@github.com>
ft_parse result code: -1

```
