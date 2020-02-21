#include "ft_printf.h"

#include <float.h>
#include <math.h>

int main()
{
    long double test_max = LDBL_MAX;
    long double test_min = LDBL_MIN;
    double test = 4.375;
    long double test1 = 123456789.777918236412341234;
    long double test2 = 1.025978548534310421;
    long double test3 = 0.00000;
    long double test4 = 2.5;
// "%f", -3.85
    double dubb = -3.85;
    ft_printf("%f", dubb);
    // printf("%.3Lf\n", dubb);
    return (0);
}