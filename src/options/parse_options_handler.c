#include <stdio.h>
#include <stdlib.h>

#include "parse_help.h"
#include "parse_color.h"

int handle_base(const int ac, const char **arg, const struct parse_option options[]) {
    (void)ac;
    (void)arg;
    (void)options;
    printf("base function. ac : %d \n", ac);
    if (!arg) {
        printf("arg : is NULL in base! \n");
    }
    return ac;
}

int handle_help(const int ac, const char **arg, const struct parse_option options[]) {
    (void)ac;
    (void)arg;
    (void)options;
    print_help(options, &PARSE_DEFAULT_THEME);
    return -1;
}

int handle_verbose(const int ac, const char **arg, const struct parse_option options[]) {
    (void)ac;
    (void)arg;
    (void)options;
    printf("Verbose mode enabled.\n");

    const char **port_str = arg;
    if (port_str) {
        printf("Verbose set to: ");
        for (int i = 0; i < ac ; i++)
        {
            printf("%s ", port_str[i]);
        }
    }
    printf("\n");

    return ac - 1;
}

int handle_count(const int ac, const char **arg, const struct parse_option options[]) {
    (void)ac;
    (void)options;
    const char **port_str = arg;
    if (port_str) {
        printf("count set to: ");
        for (int i = 0; i < ac ; i++)
        {
            printf("%s ", port_str[i]);
        }
    }
    printf("\n");

    return ac - 2;
}
