#include "ft_printf.h"
#include <limits.h>

int main(void)
{
//    char str[5];
    int i;
    long int l;
    long long ll;
    unsigned int u;
    unsigned long ul;
    unsigned long long ull;
    char *p;
    char c;

/*    i = 2147483647;
    ll =  9223372036854775807;
    ull = 9223372036854775808;*/

    c = 'f';
    p = &c;
    ft_printf("%%% m%20.15p\n", p);
    printf("%%% m%20.15p\n", p);
//    ft_printf("%.2s\n", "serebro");
//    printf("%.2s\n", "serebro");
//    fill_char(5, (char**)(&str));

    return (0);
}