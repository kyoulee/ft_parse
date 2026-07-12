#include <stddef.h>
#include "ft_parse.h"
#ifdef TEST_MODE
# include "parse_help.t.h"
# include "parse_input.t.h"
# include "parse_options_handler.h"
#endif

int main(int ac, const char **av)
{
    const struct parse_option options[] = {
        {0, NULL, "send ICMP ECHO_REQUEST to network hosts", "[options] <destination>", handle_base},
        {'v', "verbose", "Produce verbose output", NULL, handle_verbose},
        {'c', "count",  "Stop after sending NUMBER packets", "ping -c 5 google.com", handle_count},
        {'d', "debug", "Enable debug mode with extra logs", "ping --debug", NULL},
        {'h', "help",  "Give this help list", "ping --help", handle_help},
        {0, NULL, NULL, NULL, NULL}
    };
#ifdef TEST_MODE
    test_parse_help(ac, av, options);
    test_parse_input(ac, av, options);
#endif
    (void)ac;
    (void)av;
    return (0);
}