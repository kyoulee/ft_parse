#ifndef PARSE_OPTIONS_T_H
#define PARSE_OPTIONS_T_H

#include <stddef.h>
#include "ft_parse.h"
#include "parse_options_handle.h"

#define DESCRIPTION "FT_PING: A custom ping utility inspired by GNU inetutils."

/**
 * @brief 옵션 데이터 정의
 * @details 
 * 배열의 첫번때는 기본 실행 함수가 있어야합니다.
 * 첫 기본 배열을 제외한 short 와 long에 대한 인자는 필수 인자입니다.
 * 배열의 마지막은 반드시 NULL과 0으로 끝나는 Sentinel 노드여야 합니다.
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
