#include <stdio.h>

/**
 * @brief 에러 메시지를 출력하고 할당된 메모리를 해제한 뒤 NULL을 반환합니다.
 * @param message stderr에 출력할 에러 메시지
 * @return 항상 NULL을 반환합니다.
 */
void *exit_with_error(const char *message)
{
    if (message)
        fprintf(stderr, "Error: %s\n", message);
    return (NULL);
}

