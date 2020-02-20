#include "ft_printf.h"

#include <float.h>

int main()
{
    long double test_max = LDBL_MAX;
    double test = 4.25;
    long double test1 = 0.5555555555555555;
    ft_printf("our %.10Lf\n", test_max);
    // printf("std %.10Lf\n", test_max);

    // t_ldbl res;

    // res.origin = test_max;
    // printf("%u\n", res.parts.sign);
	// printf("%u\n", res.parts.exp);
	// printf("%llu\n", res.parts.mant);

    // printf("\nstd %Lf\n", test1);
    // ft_printf("our %Lf\n", test1);
    return (0);
}