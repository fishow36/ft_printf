#include "ft_printf.h"

#include <float.h>
#include <math.h>

int main()
{
    long double test_max = LDBL_MAX;
    long double test_min = LDBL_MIN;
    double test = 4.375;
    long double test1 = 123456789.777918236412341234;
    long double test2 = 12.7;
    long double test3 = 0.00000000;
    long double test4 = 0.00123456789987654321;
//   ft_printf("our %#.16o\n", -875);
    ft_printf("%.50Lf\n", test_max);
    // double dubb = NAN;
    printf("%.50Lf\n", test_max);
    return (0);
}