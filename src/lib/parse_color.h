#ifndef PARSE_COLOR_H
# define PARSE_COLOR_H

/**
 * @name Text Styles
 * @{
 */
# define RESET          "\033[0m"  /**< Reset all terminal attributes to default. */
# define BOLD           "\033[1m"  /**< Bold or increased intensity. */
# define ITALIC         "\033[3m"  /**< Italic text (not supported by all terminals). */
# define UNDERLINE      "\033[4m"  /**< Underlined text. */
/** @} */

/**
 * @name Standard Foreground Colors
 * @{
 */
# define RED            "\033[31m" /**< Standard Red text. */
# define GREEN          "\033[32m" /**< Standard Green text. */
# define YELLOW         "\033[33m" /**< Standard Yellow text. */
# define BLUE           "\033[34m" /**< Standard Blue text. */
# define MAGENTA        "\033[35m" /**< Standard Magenta text. */
# define CYAN           "\033[36m" /**< Standard Cyan text. */
# define WHITE          "\033[37m" /**< Standard White text. */
/** @} */

/**
 * @name High-Intensity Foreground Colors
 * @{
 */
# define BRIGHT_BLACK   "\033[90m" /**< Bright Black (Dark Gray) text. */
# define BRIGHT_RED     "\033[91m" /**< Bright Red text. */
# define BRIGHT_GREEN   "\033[92m" /**< Bright Green text. */
# define BRIGHT_YELLOW  "\033[93m" /**< Bright Yellow text. */
# define BRIGHT_BLUE    "\033[94m" /**< Bright Blue text. */
# define BRIGHT_MAGENTA "\033[95m" /**< Bright Magenta text. */
# define BRIGHT_CYAN    "\033[96m" /**< Bright Cyan text. */
# define BRIGHT_WHITE   "\033[97m" /**< Bright White text. */
/** @} */

/**
 * @struct parse_theme
 * @brief Representation of a display theme configuration for parser outputs.
 * * Holds the ANSI escape sequence pointers designated for different structural
 * components of the help and error layout.
 */
struct parse_theme {
    char *label;      /**< Style for headers and section labels (e.g., "Usage:"). */
    char *option;     /**< Style for option flags (e.g., "-s", "--long"). */
    char *desc;       /**< Style for descriptive text elements. */
    char *example;    /**< Style for example cases and operational hints. */
    char *reset;      /**< The default reset sequence to close styled blocks. */
};

extern const struct parse_theme PARSE_DEFAULT_THEME;

#endif
