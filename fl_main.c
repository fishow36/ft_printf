#include "ft_printf.h"

#include<float.h>

int main()
{
    long double test1 = 12800000000000.1230000001234;
    printf("std\t%.50Lf\n", test1);
    ft_printf("our\t%.50Lf\n", test1);
    
    return (0);
}