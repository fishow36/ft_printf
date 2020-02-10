#include "ft_printf.h"

void print_bit(t_ulli num, int shift)
{
    int i = --shift;
    int counter; 
    
    counter = 0;
    while (i > -1)
    {
        if (i > 31)
        {
            if (num & (1 << 31) << (i - 31))
                printf("1");
            else
                printf("0");
        }
        else
        {
            if (num & (1 << i))
                printf("1");
            else
                printf("0");            
        }
        i--;
    }
    printf(" ");
}

void    print_ldbl(t_ldbl to_print)
{
    printf("\nmanti\n");
    print_bit(to_print.parts.mant, 64);
    printf("\nsign\texpo\n");
    print_bit(to_print.parts.sign, 1);
    printf("    ");
    print_bit(to_print.parts.exp, 15);
    printf("\n");
}

void    print_dbl(t_dbl to_print)
{
    printf("\nmanti\n");
    print_bit(to_print.parts.mant, 52);
    printf("\nsign\texpo\n");
    print_bit(to_print.parts.sign, 1);
    printf("    ");
    print_bit(to_print.parts.exp, 11);
    printf("\n");
}

void    print_float(t_lst *temp, double input)
{
    t_dbl   res;

    res.origin = input;
    printf("%u\n", res.parts.sign);
    printf("%u\n", res.parts.exp);
    printf("%llu\n", res.parts.mant);
}

void    print_lfloat(t_lst *temp, long double input)
{
    t_ldbl  res;

    res.origin = input;
}