#ifndef PARSE_OPTIONS_T_H
# define PARSE_OPTIONS_T_H

#include <stddef.h>
#include "ft_parse.h"
#include "parse_options_handler.h"

/**
 * @def DESCRIPTION
 * @brief Template program identification string. 
 * @note Replace this string with your specific application name and description.
 */
#define DESCRIPTION "FT_PING: A custom ping utility inspired by GNU inetutils."

/**
 * @brief Example layout array defining supported command-line options.
 *
 * @details
 * This static array serves as a template for users configuring the ft_parse library.
 * To customize for your own application, modify the elements while maintaining these invariants:
 * - **Index 0 (Baseline Handler):** Reserved for positional non-option arguments 
 * (e.g., target hostnames). Flags (`short_opt`, `long_opt`) must be null/0.
 * - **Indices 1 to N-2 (Standard Options):** Explicit option flags. Both 
 * `short_opt` and `long_opt` are required for proper token mapping.
 * - **Index N-1 (Sentinel Node):** The array must be explicitly terminated 
 * with an empty structure `{0, NULL, NULL, NULL, NULL}` to safe-guard loop boundaries.
 */
static const struct parse_option options[] = {
    {0, NULL, NULL, "send ICMP ECHO_REQUEST to network hosts", handle_base},
    {'v', "verbose", "Produce verbose output", NULL, handle_verbose},
    {'c', "count",  "Stop after sending NUMBER packets", "ping -c 5 google.com", handle_count},
    {'d', "debug", "Enable debug mode with extra logs", "ping --debug", NULL},
    {'h', "help",  "Give this help list", "ping --help", handle_help},
    {0, NULL, NULL, NULL, NULL}
};

#endif