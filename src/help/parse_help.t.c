#include <stdio.h>
#include "ft_parse.h"
#include "parse_help.h"
#include "parse_options.h"

int test_parse_help(int argc, const char **argv) {
    (void)argv;
    if (argc < 2) {
        print_help(argv[0], DESCRIPTION , options);
        return -1;
    }

    printf("Program is running with %d arguments...\n", argc - 1);
    
    return 0;
};