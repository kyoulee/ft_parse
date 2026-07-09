#ifndef PARSE_OPTIONS_HANDLE_H
#define PARSE_OPTIONS_HANDLE_H

#include "ft_parse.h"


/* 리턴의 규칙을 만들자 
 * 0크그먼트가 남지안고 잘 실행 되었다
 * + 단위 아그먼트가 남아 다음 기본 실행에 넣어주어야 한다.
 * - 단위는 다음 과정을 멈추도록 한다. 
 * 에러정의의 경우는 핸들러 안에서 처리하도록 한다.
*/
/* Handlers */
int handle_base(const int ac, const char **arg);
int handle_help(const int ac, const char **arg);
int handle_verbose(const int ac, const char **arg);
int handle_count(const int ac, const char **arg);

#endif

