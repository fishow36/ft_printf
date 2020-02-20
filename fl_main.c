#include "ft_printf.h"

#include <float.h>

int main()
{
    long double test_max = LDBL_MAX;
    long double test_min = LDBL_MIN;
    double test = 4.25;
    long double test1 = 100000000000000.00000;
    ft_printf("our %.55Lf\n", test_min);
    printf("std %.55Lf\n", test_min);

    // t_ldbl res;

    // res.origin = test_max;
    // printf("%u\n", res.parts.sign);
	// printf("%u\n", res.parts.exp);
	// printf("%llu\n", res.parts.mant);

    // printf("\nstd %Lf\n", test1);
    // ft_printf("our %Lf\n", test1);
    return (0);
}