#include <stdio.h>
#include "parse_help.t.h"

int test_parse_help(int argc, const char **argv, const struct parse_option options[] ) {
    (void)argc;
    (void)argv;
    print_help(options, &PARSE_DEFAULT_THEME);
    
    return 0;
};
