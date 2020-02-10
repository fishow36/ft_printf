#include "ft_printf.h"
#

int main()
{
    double test = 1.25;
    long double test1 = 1.25;

    printf("std %f\n", test);
    ft_printf("our %f\n", test);

    // printf("\nstd %Lf\n", test1);
    // ft_printf("our %Lf\n", test1);
    return (0);
}