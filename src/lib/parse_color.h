//
// Created by kyoulee on 26. 1. 27..
//

#ifndef PARSE_COLOR_H
#define PARSE_COLOR_H

/* 텍스트 스타일 */
# define RESET          "\033[0m"
# define BOLD           "\033[1m"
# define ITALIC         "\033[3m"
# define UNDERLINE      "\033[4m"

/* 일반 색상 */
# define RED            "\033[31m"
# define GREEN          "\033[32m"
# define YELLOW         "\033[33m"
# define BLUE           "\033[34m"
# define MAGENTA        "\033[35m"
# define CYAN           "\033[36m"
# define WHITE          "\033[37m"

/* 밝은 색상 (High Intensity) */
# define BRIGHT_BLACK   "\033[90m"
# define BRIGHT_RED     "\033[91m"
# define BRIGHT_GREEN   "\033[92m"
# define BRIGHT_YELLOW  "\033[93m"
# define BRIGHT_BLUE    "\033[94m"
# define BRIGHT_MAGENTA "\033[95m"
# define BRIGHT_CYAN    "\033[96m"
# define BRIGHT_WHITE   "\033[97m"

/* 고급 색생 */

// 프로그램 테마에 맞는 구조체
struct parse_theme {
    char *label;      // Usage, Options 같은 제목용
    char *option;     // -s, --long 같은 옵션용
    char *desc;       // 설명 텍스트용
    char *example;    // 예시용 (이탤릭 회색)
    char *reset;      // 초기화
};

#endif