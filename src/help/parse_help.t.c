#include <stdio.h>
#include "parse_help.t.h"

int test_parse_help(int argc, const char **argv) {
    (void)argc;
    (void)argv;
    print_help(DESCRIPTION , options, &DEFAULT_THEME);
    
    return 0;
};
