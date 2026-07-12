
#include <stddef.h>
#include "ft_parse.h"

int main(int ac, const char **av)
{
    const struct parse_option options[] = {
        {0, NULL, NULL, "send ICMP ECHO_REQUEST to network hosts", NULL},
        {0, NULL, NULL, NULL, NULL}
    };

    return (ft_parse(ac,av, options));
}