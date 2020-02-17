#include "ft_printf.h"

int main()
{
    double test = 4.25;
    long double test1 = -0.00000000000025;

    printf("std %Lf\n", test1);
    ft_printf("our %Lf\n", test1);

    // printf("\nstd %Lf\n", test1);
    // ft_printf("our %Lf\n", test1);
    return (0);
}