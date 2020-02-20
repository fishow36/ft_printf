#include "ft_printf.h"

#include <float.h>

int main()
{
    long double test_max = LDBL_MAX;
    long double test_min = LDBL_MIN;
    double test = 4.25;
    long double test1 = 100000000000000.00000;
    long double test2 = 1234321.912834;
    long double test3 = 0.00000000;
    long double test4 = 0.00123456789;
    
    ft_printf("our %.51Lf\n", test2);
    printf("std %.51Lf\n", test2);

    // ft_printf("%.51Lf\n", test1);
    // ft_printf("%.51Lf\n", test2);
    // ft_printf("%.51Lf\n", test3);
    // ft_printf("%.51Lf\n", test4);
    return (0);
}