#ifndef PARSE_OPTIONS_HANDLE_H
#define PARSE_OPTIONS_HANDLE_H

#include "ft_parse.h"

/* Handlers */
int handle_base(const int ac, const char **arg);
int handle_help(const int ac, const char **arg);
int handle_verbose(const int ac, const char **arg);
int handle_count(const int ac, const char **arg);

#endif

