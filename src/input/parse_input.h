#ifndef FT_PARSE_PARSE_INPUT_H
#define FT_PARSE_PARSE_INPUT_H

#include "ft_parse.h"

struct parse_input *parse_input(int argc, char **argv);

struct parse_option_node {
    struct parse_option* option;
    char **argv;
    struct parse_option_node *next;
};

const struct parse_option *find_short_opt(const struct parse_option *opts, const char c);
const struct parse_option *find_long_opt(const struct parse_option *opts, const char *name);

struct parse_input {
    struct parse_option_node *head;
    struct parse_option_node *tail;
};

#endif