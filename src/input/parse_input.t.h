#ifndef FT_PARSE_PARSE_INPUT_T_H
# define FT_PARSE_PARSE_INPUT_T_H

#include "parse_input.h"

/**
 * @brief Runs unit tests for the parse_input module.
 *
 * Validates whether command-line arguments are properly tokenized,
 * mapped to their corresponding options, and tracked with accurate argument counts.
 *
 * @param[in] argc  Argument count (typically matching argc from main).
 * @param[in] argv  Array of argument strings (typically matching argv from main).
 * @return int      Returns 0 on all tests passing, or -1 if any validation fails.
 */
int test_parse_input(int argc, const char **argv);

#endif  // FT_PARSE_PARSE_INPUT_T_H
