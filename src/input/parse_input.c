#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "parse_input.h"
#include "parse_error.h"
#include "parse_options.h"

/* Helper: Find option by short flag */
const struct parse_option *find_short_opt(const struct parse_option *opts, const char c) {
    if (!opts) return NULL;
    for (int i = 1; opts[i].short_opt != 0; i++) {
        if (opts[i].short_opt == c) {
            return &opts[i];
        }
    }
    return NULL;
}

/* Helper: Find option by long name */
const struct parse_option *find_long_opt(const struct parse_option *opts, const char *name) {
    if (!opts) return NULL;
    for (int i = 1; opts[i].long_opt != NULL; i++) {
        if (opts[i].long_opt && strcmp(opts[i].long_opt, name + 2) == 0) {
            return &opts[i];
        }
    }
    return NULL;
}


struct parse_input_item *parse_input(int argc, const char **argv) {
    struct parse_input_item *items = calloc(argc, sizeof(struct parse_input_item) + 1);
    int t = 0;
    const struct parse_option *option;
    if (!items)
		return exit_with_error("Memory allocation failed for input node");
    items[t].option = &options[0];
    for (int i = 1; i < argc; i++) {
        if (!argv[i])
            break ;
        if (argv[i][0] == '-') {
            t++ ;
            if (argv[i][1] == '-')
                option = find_long_opt(options, argv[i]);
            else
                option = find_short_opt(options, argv[i][1]);
            if (!option) {
                exit_with_error("wrong option \n");
                return items ;
            }
            items[t].option = option;
            items[t].argv = &argv[i];
            printf("option is %s \n", option->long_opt);
        }
        items[t].arg_count++;
    }
    if (items[0].arg_count) {
        items[0].argv = &argv[1];
    }
    return (items);
}
