#include "ft_parse.h"
#ifdef TEST_MODE
# include "parse_help.t.h"
# include "parse_input.t.h"
#endif

int main(int ac, const char **av)
{
#ifdef TEST_MODE
    // test_parse_help(ac, av);
    test_parse_input(ac, av);
#endif
    (void)ac;
    (void)av;
    return (0);
}