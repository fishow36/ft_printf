#include "ft_printf.h"

#include <float.h>

int main()
{
    long double test_max = LDBL_MAX;
    double test = 4.25;
    long double test1 = 10000000000000000000000.0;
    ft_printf("our %Lf\n", test1);
    // printf("std %Lf\n", test1);

    // t_ldbl res;

    // res.origin = test_max;
    // printf("%u\n", res.parts.sign);
	// printf("%u\n", res.parts.exp);
	// printf("%llu\n", res.parts.mant);

    // printf("\nstd %Lf\n", test1);
    // ft_printf("our %Lf\n", test1);
    return (0);
}