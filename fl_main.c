#include "ft_printf.h"

int main()
{
    double test = 1.25;
    long double test1 = 0.125;
    
    // printf("std %f\n", test);
    // ft_printf("our %f\n", test);

    printf("\nstd %Lf\n", test1);
    ft_printf("our %Lf\n", test1);

    return (0);
}

// t_val ft_cast(long double *n)
// {
//     t_val kek;
//     unsigned long long int *number;
    
//     number = (unsigned long long int *)n;
//     kek.mantisa = number[0];
//     kek.order = (number[1] & 0x7fff) - ;
//     kek.sign = (number[1] & 0x8000) > 15;
//     return (kek);
// }