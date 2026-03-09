#ifndef PARSE_OPTIONS_T_H
#define PARSE_OPTIONS_T_H

#include "ft_parse.h"
#include "parse_options_handle.h"

#define DESCRIPTION "FT_PING: A custom ping utility inspired by GNU inetutils."

/**
 * @brief 옵션 데이터 정의
 * @details 배열의 마지막은 반드시 NULL과 0으로 끝나는 Sentinel 노드여야 합니다.
 */
static const struct parse_option options[] = {
    {'v', "verbose", "Produce verbose output", NULL, handle_verbose},
    {'c', "count",  "Stop after sending NUMBER packets", "ping -c 5 google.com", handle_count},
    {'d', "debug", "Enable debug mode with extra logs", "ping --debug", NULL},
    {0, "help",  "Give this help list", "ping --help", handle_help},
    {0, NULL, NULL, NULL, NULL}
};

#endif
