#ifndef PARSE_OPTIONS_HANDLER_H
#define PARSE_OPTIONS_HANDLER_H

#include "ft_parse.h"

/**
 * @brief Template declarations for command-line option callback handlers.
 *
 * @details
 * ### HANDLER RETURN VALUE RULES
 * Each option handler must return an integer status code enforcing the following logic:
 * - **0 (Success / Consumed):** All associated arguments were successfully processed. No remaining arguments.
 * - **Positive (> 0):** Specifies the number of trailing arguments that were not consumed 
 * by this handler. These will be forwarded directly to the baseline handler.
 * - **Negative (< 0):** Indicates a fatal execution error or early exit trigger (e.g., --help). 
 * The parser engine will halt immediately and terminate the cascading chain.
 *
 * @note Internal errors, formatting, and logs should be managed encapsulated within each handler.
 */

/**
 * @brief Baseline handler executed for remaining positional arguments (e.g., target host).
 */
int handle_base(const int ac, const char **arg, const struct parse_option options[]);

/**
 * @brief Execution handler triggered by the help option.
 */
int handle_help(const int ac, const char **arg, const struct parse_option options[]);

/**
 * @brief Execution handler triggered by the verbose option.
 */
int handle_verbose(const int ac, const char **arg, const struct parse_option options[]);

/**
 * @brief Execution handler triggered by the count option.
 */
int handle_count(const int ac, const char **arg, const struct parse_option options[]);

#endif