#include "ft_parse.h"
#ifdef TEST_MODE
# include "test.h"
#endif

int main(int ac, char **av)
{
#ifdef TEST_MODE
    //test_parse_help(ac, av);
    //test_parse_input(ac,∑av);
#endif
    (void)ac;
    (void)av;
    ft_parse(ac,av);
    return (0);
}