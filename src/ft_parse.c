#include "ft_parse.h"
#include "parse_input.h"
#include <stdio.h>
#include <stdlib.h>
int ft_parse(int argc, char **argv) {
    struct parse_input_item *parse_items = parse_input(argc, argv);
    
    if (parse_items)
    {
    }
    
    // 메모리 누수 없이 깔끔하게 원샷 해제
    free(parse_items);
    return 0;
}
