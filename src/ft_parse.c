#include "ft_parse.h"
#include "parse_input.h"
#include "parse_options.h"
#include <stdio.h>
#include <stdlib.h>

int ft_parse(int argc, const char **argv) {
    struct parse_input_item *parse_items = parse_input(argc, argv);
    int remainder = 0;

    if (parse_items)
    {
        int i = 1;
        while (parse_items[i].option)
        {
            if (!parse_items[i].option->handler) {
                printf("handler function is NULL \n");
                i++;
                continue;
            }
            remainder = parse_items[i].option->handler(
                parse_items[i].arg_count,
                parse_items[i].argv
            );
            if (remainder) {
                if (remainder < 0 ) {
                    printf("option input is not enough for option [%s] \n", parse_items[i].option->long_opt);
                    free(parse_items);
                    return 2;
                }
                parse_items[0].arg_count = remainder;
                parse_items[0].argv = parse_items[i].argv + (parse_items[i].arg_count - remainder);
                remainder = 0;
            }
            i++;
        }
        if (!parse_items[0].option->handler) {
            printf("handler base is not Founded \n");
            free(parse_items);
            return 1;
        }
        parse_items[0].option->handler(
            parse_items[0].arg_count,
            parse_items[0].argv
        );
    }

    free(parse_items);
    return 0;
}
