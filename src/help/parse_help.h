#ifndef PARSE_HELP_H
# define PARSE_HELP_H

#include "ft_parse.h"
#include "parse_color.h"

/**
 * @brief Prints the program usage block.
 * @param[in] program_name  The name of the executable.
 * @param[in] theme         Color theme configuration.
 */
void print_Usage(const char *program_name, const struct parse_theme *theme);

/**
 * @brief Prints the program description block.
 * @param[in] descript      A brief summary of the program's purpose.
 * @param[in] theme         Color theme configuration.
 */
void print_description(const char *descript, const struct parse_theme *theme);

/**
 * @brief Prints the formatted list of command-line options.
 * @param[in] opts   Pointer to the parse_option array (terminated by long_opt == NULL).
 * @param[in] theme  Color theme configuration.
 */
void print_options(const struct parse_option *opts, const struct parse_theme *theme);

/**
 * @brief Prints the entire help menu to stdout.
 * @param[in] descript      Program description. Omitted if NULL.
 * @param[in] opts          Pointer to the parse_option array.
 * @param[in] theme         Color theme configuration.
 */
void print_help(const struct parse_option *opts, const struct parse_theme *theme);

#endif  // PARSE_HELP_H_
