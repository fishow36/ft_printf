//#include "ft_printf.h"
//#include <limits.h>

#include "ft_printf.h"

int main(void)
{
    int i;
    long int l;
    long long ll;
    unsigned int u;
    unsigned long ul;
    unsigned long long ull;
    double *p;
    char c;
    double f;
    char *str;

    f = 1.0;
    p = &f;
    
    u = 4294967295;
    i = -2147483649;
    ft_printf("%lld\n", 18446744073709551615);
    printf("%lld\n", 18446744073709551615);
    return (0);
}