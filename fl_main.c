#include "ft_printf.h"

int main()
{
    double test = 4.25;
    long double test1 = 1234123412340.0001234567890987654321;

    printf("std\t%.52Lf\n", test1);
    ft_printf("our\t%.52Lf\n", test1);

    // printf("\nstd %Lf\n", test1);
    // ft_printf("our %Lf\n", test1);
    return (0);
}