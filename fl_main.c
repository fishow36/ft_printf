#include "ft_printf.h"

#include <float.h>

int main()
{
    long double test_max = LDBL_MAX;
    long double test_min = LDBL_MIN;
    double test = 4.25;
    long double test1 = 100000000000000.00000;
    long double test2 = 12345678987654321.;
    long double test3 = 0.00000000;
    long double test4 = 0.00000000123456789;
    
    ft_printf("our %.55Lf\n", test_min);
    printf("std %.55Lf\n", test_min);

    ft_printf("%.51Lf\n", test1);
    ft_printf("%.51Lf\n", test2);
    ft_printf("%.51Lf\n", test3);
    ft_printf("%.51Lf\n", test4);

    // t_ldbl res;

    // res.origin = test_max;
    // printf("%u\n", res.parts.sign);
	// printf("%u\n", res.parts.exp);
	// printf("%llu\n", res.parts.mant);

    // printf("\nstd %Lf\n", test1);
    // ft_printf("our %Lf\n", test1);
    return (0);
}