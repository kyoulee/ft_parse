#ifndef PARSE_HELP_T_H
# define PARSE_HELP_T_H

#include "parse_help.h"
#include "parse_color.h"

/**
 * @brief Runs the unit tests for the parse_help module.
 *
 * Simulates a command-line execution environmental setup to validate
 * the help menu formatting, theme injection, and argument parsing logic.
 *
 * @param[in] ac  Argument count (typically matching argc from main).
 * @param[in] av  Array of argument strings (typically matching argv from main).
 * @param[in] options  Pointer to the contiguous array of parsing options, terminated by a sentinel node.
 * @return int    Returns 0 on test success, or a non-zero error code on failure.
 */
int test_parse_help(int ac, const char **av, const struct parse_option options[] );

#endif

