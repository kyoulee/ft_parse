#ifndef FT_PARSE_H
#define FT_PARSE_H

/* Structure inspired by GNU inetutils-2.0 */
struct parse_option {
    char short_opt;           // Short option (e.g., 'v')
    const char *long_opt;     // Long option name (e.g., "verbose")
    const char *arg_name;     // Name of argument if required (e.g., "COUNT")
    const char **args_opt;    // Option args array
    const char *description;  // Detailed explanation of the option
    const char *example_case; // Example case for how to use
    void (*handler)(void *arg); // Function pointer to the handler
};

struct parse_options {
    parse_option* parse_options
}

#endif