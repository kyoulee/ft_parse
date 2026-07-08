#ifndef FT_PARSE_PARSE_INPUT_H
#define FT_PARSE_PARSE_INPUT_H

#include "ft_parse.h"

struct parse_input_item {
    const struct parse_option* option;
    const char **argv;
    int arg_count;
};

struct parse_input_item *parse_input(int argc, const char **argv);

const struct parse_option *find_short_opt(const struct parse_option *opts, const char c);
const struct parse_option *find_long_opt(const struct parse_option *opts, const char *name);

#endif