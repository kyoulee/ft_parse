#include <stdio.h>
#include "ft_parse.h"
#include "parse_help.h"

/**
 * @brief 테스트용 핸들러 함수
 */
void handle_debug(void *arg) { (void)arg; };

/**
 * @brief 옵션 데이터 정의
 * @details 배열의 마지막은 반드시 NULL과 0으로 끝나는 Sentinel 노드여야 합니다.
 */
struct parse_option options[] = {
    {'v', "verbose", NULL, NULL, "Produce verbose output", NULL, NULL},
    {'c', "count", "NUMBER", NULL, "Stop after sending NUMBER packets", "ping -c 5 google.com", NULL},
    {'d', "debug", NULL, NULL, "Enable debug mode with extra logs", "ping --debug", handle_debug},
    {0, "help", NULL, NULL, "Give this help list", "ping --help", NULL},
    {0, NULL, NULL, NULL, NULL, NULL, NULL}
};

int test_parse_help(int argc, char **argv) {
    const char *description = "FT_PING: A custom ping utility inspired by GNU inetutils.";
    (void)argv;
    if (argc < 2) {
        print_help(argv[0],description, options);
        return -1;
    }

    printf("Program is running with %d arguments...\n", argc - 1);
    
    return 0;
};