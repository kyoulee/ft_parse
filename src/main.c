#include "ft_parse.h"
#ifdef TEST_MODE
# include "test.h"
#endif

int main(int ac, char **av)
{
#ifdef TEST_MODE
    test_parse_help(ac, av);
#endif
    (void)ac;
    (void)av;
    return (0);
}