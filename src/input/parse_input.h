#ifndef FT_PARSE_PARSE_INPUT_H
# define FT_PARSE_PARSE_INPUT_H

#include "ft_parse.h"
#include "parse_options.h"

/**
 * @struct parse_input_item
 * @brief Represents a parsed command-line argument group mapped to an option.
 */
struct parse_input_item {
    const struct parse_option* option; /**< Pointer to the matched option definition. */
    const char **argv;                /**< Pointer to the starting position in the original argv array. */
    int arg_count;                     /**< Number of positional arguments or values associated with this option. */
};

/**
 * @brief Searches for an option structure by its short option character.
 * @param[in] opts       Pointer to the parse_option array.
 * @param[in] c          The short option character to find (e.g., 'h').
 * @return const struct parse_option* Pointer to the matching option, or NULL if not found.
 */
const struct parse_option *find_short_opt(const struct parse_option *opts, const char c);

/**
 * @brief Searches for an option structure by its long option name.
 * @param[in] opts       Pointer to the parse_option array.
 * @param[in] name       The full argument string starting with "--" (e.g., "--help").
 * @return const struct parse_option* Pointer to the matching option, or NULL if not found.
 * @note Skips the first two characters of the input name string to extract the raw long option.
 */
const struct parse_option *find_long_opt(const struct parse_option *opts, const char *name);

/**
 * @brief Parses command-line arguments and maps them to their respective options.
 * @param[in] argc       Argument count from the main entry point.
 * @param[in] argv       Array of argument strings from the main entry point.
 * @return struct parse_input_item* Dynamic array of parsed items, or NULL on memory allocation failure.
 * @note 
 * - The returned array is dynamically allocated and contains structured groups of options and arguments.
 * - Enforces rigorous error handling; terminates or reports error if an invalid option is encountered.
 */
struct parse_input_item *parse_input(int argc, const char **argv);

#endif
