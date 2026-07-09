#include <stdio.h>
#include <string.h>
#include "parse_help.h"

void print_Usage(const char *program_name, const struct parse_theme *theme) {
    if (!program_name)
        return;
    printf("%sUsage%s\n",theme->label, theme->reset);
    printf("  %s [%sOPTION%s...]\n", program_name, theme->option, theme->reset);
}

void print_description(const char *descript, const struct parse_theme *theme) {
    if (!descript)
        return;
    printf("\n%sDESCRIPTION%s\n", theme->label, theme->reset);
    printf("  %s\n", descript);
}

void print_options(const struct parse_option *opts ,const struct parse_theme *theme) {
    if (!opts)
        return;
    printf("\n%sOptions%s\n", theme->label, theme->reset);
    for (int i = 1; opts[i].long_opt != NULL; i++) {
        char left_side[128] = {0};
        char opt_buf[64] = {0};

        if (opts[i].short_opt) {
            snprintf(left_side, sizeof(left_side), "  -%c, ", opts[i].short_opt);
        } else {
            snprintf(left_side, sizeof(left_side), "      ");
        }

        if (opts[i].long_opt) {
            snprintf(opt_buf, sizeof(opt_buf), "--%s", opts[i].long_opt);
        } else {
            snprintf(opt_buf, sizeof(opt_buf), "--(unknown)");
        }
        
        strncat(left_side, opt_buf, sizeof(left_side) - strlen(left_side) - 1);
        
        printf("%s%-30s%s %s%s%s\n", 
               theme->option, left_side, theme->reset,
               theme->desc, opts[i].description ? opts[i].description : "", theme->reset);

        if (opts[i].example_case) {
            printf("%-32s %sEx: %s%s\n", 
                   "", theme->example, opts[i].example_case, theme->reset);
        }
    }
}

void print_help(const char *descript, const struct parse_option *opts, const struct parse_theme *theme) 
{
    if (!opts || !theme) {
        printf("NO Help option\n");
        return ;
    }
    extern char *program_invocation_short_name;

    print_Usage(program_invocation_short_name, theme);
    print_description(descript, theme);
    print_options(opts,theme);

    printf("\n----------------------------------------------------------\n");
    printf("Report bugs to: <kyoulee@github.com>\n");
}
