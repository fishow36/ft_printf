#include "ft_printf.h"


int main()
{
    double test = 1.25;
    long double test1 = 100.332423;
    int         for_lan = 123456789;

    create_lan((t_ulli)for_lan);

    // printf("std %f\n", test);
    // ft_printf("our %f\n", test);

    // printf("\nstd %Lf\n", test1);
    // ft_printf("our %Lf\n", test1);

    return (0);
}