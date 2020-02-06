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
    int *p;
    int d;

/*    i = 2147483647;
    ll =  9223372036854775807;
    ull = 9223372036854775808;*/
    ft_printf("%0.0m\n", 18);
    printf("%0.0m\n", 18);
//    ft_printf("%.2s\n", "serebro");
//    printf("%.2s\n", "serebro");
//    fill_char(5, (char**)(&str));


    return (0);
}