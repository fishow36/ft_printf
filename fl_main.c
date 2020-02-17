#include "ft_printf.h"

#include<float.h>
#include <math.h>

int main()
{
    // long double test1 = 12800000000000.1230000001234;
    // long double test_max = LDBL_MAX;
    // long double test_min = LDBL_MIN;
    // long double test_inf = ;

    // printf("std\t%.50Lf\n\n\n\n%.50Lf\n", test_max, test_min);
    // printf("std\t%Lf\n", 1.0 / 0.0);
    printf("std\t%Lпf\n", sqrt(- 1 / 2));
    ft_printf("std\t%Lf\n", sqrt(- 1 / 2));

    // printf("std\t%f\n\n", -1.0 / 0.0);
    // ft_printf("our\t%f\n", 1.0 / 0.0);
    // ft_printf("our\t%f\n\n", 0.0 / 0.0);
    // ft_printf("our\t%.50Lf\n", test1);
    
    return (0);
}