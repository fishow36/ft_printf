#include "ft_printf.h"

int main(void)
{
//    char str[5];
    int i;
    long int l;
    long long ll;
    unsigned int u;
    unsigned long ul;
    unsigned long long ull;

    i = 2147483647;
    ll =  9223372036854775807;
    ft_printf("%lld\n", ll);
    printf("%lld\n", ll);
//    ft_printf("%.2s\n", "serebro");
//    printf("%.2s\n", "serebro");
//    fill_char(5, (char**)(&str));


    return (0);
}