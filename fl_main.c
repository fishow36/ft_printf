#include "ft_printf.h"

int main()
{
    double test = 4.25;
    long double test1 = 0.5555555555555555;

    printf("std %.10Lf\n", test1);
    ft_printf("our %.10Lf\n", test1);

    // printf("\nstd %Lf\n", test1);
    // ft_printf("our %Lf\n", test1);
    return (0);
}