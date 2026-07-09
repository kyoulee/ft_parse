#ifndef FT_PARSE_H
# define FT_PARSE_H

/**
 * @struct parse_option
 * @brief Command-line option definition structure inspired by GNU inetutils.
 */
struct parse_option {
    char short_opt;           /**< Short option character (e.g., 'v') */
    const char *long_opt;      /**< Long option name (e.g., "verbose") */
    const char *description;   /**< Detailed explanation of the option */
    const char *example_case;  /**< Example case for how to use */
    
    /**
     * @brief Callback function pointer executed when the option is matched.
     * @param[in] ac   The argument count associated with this option.
     * @param[in] arg  The array of argument strings for this option.
     * @return int     Remaining positional arguments, 0 on success, or negative on fatal error.
     */
    int (*handler)(const int ac, const char **arg);
};

/**
 * @brief Main execution core of the command-line argument parser.
 *
 * Iterates through tokenized parsing input items, sequentially invokes matching
 * handler callback functions, manages error cascading, and transfers remaining
 * positional arguments to the baseline handler.
 *
 * @param[in] argc  Argument count from the program main entry point.
 * @param[in] argv  Array of argument strings from the program main entry point.
 * @return int      Returns 0 on complete parsing success,
 * 1 if the baseline handler is missing,
 * 2 on a fatal option handler error, or
 * -1 on initial memory allocation failure.
 */
int ft_parse(int argc, const char **argv);

#endif