#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "parse_input.h"
#include "parse_error.h"
#include "parse_options.h"

/* Helper: Find option by short flag */
const struct parse_option *find_short_opt(const struct parse_option *opts, const char c) {
    if (!opts) return NULL;
    for (int i = 0; opts[i].short_opt != 0; i++) {
        if (opts[i].short_opt == c) {
            return &opts[i];
        }
    }
    return NULL;
}

/* Helper: Find option by long name */
const struct parse_option *find_long_opt(const struct parse_option *opts, const char *name) {
    if (!opts) return NULL;
    for (int i = 0; opts[i].long_opt != NULL; i++) {
        if (opts[i].long_opt && strcmp(opts[i].long_opt, name + 2) == 0) {
            return &opts[i];
        }
    }
    return NULL;
}


struct parse_input *parse_input(int argc, char **argv) {
    struct parse_input *node = malloc(sizeof(struct parse_input));
    if (!node)
		return exit_with_error("Memory allocation failed for input node");
    node->head = NULL;
    node->tail = NULL;
    const struct parse_option *option = NULL;
    for (int i = 1; i < argc; i++) {
        if (!argv[i])
            break;
        if (argv[i][0] == '-') {
            if (argv[i][1] == '-')
                option = find_long_opt(options, argv[i]);
            else
                option = find_short_opt(options, argv[i][1]);
            if (!option)
                    exit_with_error("wrong option \n");
            else
                printf("option is %s \n", option->long_opt);
        }
    }
    return (node);
}
