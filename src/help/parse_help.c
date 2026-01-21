#include <stdio.h>
#include <string.h>
#include "ft_parse.h"

/**
 * @brief 명령행 옵션 도움말을 표준 출력으로 출력합니다.
 * @param program_name 프로그램 이름
 * @param descript 프로그램 상세 설명
 * @param opts 옵션 정보 배열
 */
void print_help(const char *program_name, const char *descript, struct parse_option *opts) {
    printf("\033[1mUsage:\033[0m %s [\033[4mOPTION\033[0m...]\n", program_name);
    
    if (descript) {
        printf("\n%s\n", descript);
    }

    printf("\n\033[1mOptions:\033[0m\n");

    for (int i = 0; opts[i].long_opt != NULL; i++) {
        char left_side[128] = {0};
        char opt_buf[64] = {0};

        if (opts[i].short_opt) {
            sprintf(left_side, "  -%c, ", opts[i].short_opt);
        } else {
            sprintf(left_side, "      ");
        }

        if (opts[i].opt_name) {
            sprintf(opt_buf, "--%s=%s", opts[i].long_opt, opts[i].opt_name);
        } else {
            sprintf(opt_buf, "--%s", opts[i].long_opt);
        }
        strcat(left_side, opt_buf);

        printf("%-30s %s\n", left_side, opts[i].description);

        if (opts[i].example_case) {
            printf("%-32s \033[3;90mEx: %s\033[0m\n", "", opts[i].example_case);
        }
    }

    printf("\n----------------------------------------------------------\n");
    printf("Report bugs to: <kyoulee@github.com>\n");
}