#include "ft_printf.h"
#

int main()
{
    double test = 1.5;
    long double test1 = 3.125;

    printf("std %f\n", test);
    ft_printf("our %f\n", test);
    return (0);
}