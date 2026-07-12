#include "parse_input.t.h"
#include <stdio.h>
#include <stdlib.h>

int test_parse_input(int argc, const char **argv, const struct parse_option options[] ) {
    printf("[TEST] Starting parse_input unit test...\n");

    struct parse_input_item *parse_items = parse_input(argc, argv, options);
    
    if (!parse_items) {
        printf("[FAIL] parse_input returned NULL pointer.\n");
        return -1;
    }
    printf("[INFO] Checking parsed items layout:\n");
    for (int i = 0; i < argc; i++) {
        if (parse_items[i].option == NULL && parse_items[i].arg_count == 0) {
            break;
        }

        printf("  Item [%d]: option_ptr=%p, arg_count=%d", 
               i, (void*)parse_items[i].option, parse_items[i].arg_count);
        
        if (parse_items[i].option && parse_items[i].option->long_opt) {
            printf(" (long_opt: --%s)", parse_items[i].option->long_opt);
        }
        printf("\n");
    }

    free(parse_items);
    parse_items = NULL;

    printf("[SUCCESS] parse_input unit test completed successfully.\n");
    return 0;
}
