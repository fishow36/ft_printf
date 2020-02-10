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

unsigned    exp_shift(unsigned exp, unsigned *shift, unsigned dbl_ldbl)
{
    if (dbl_ldbl == 1)
    {
        *shift = exp - 1023;
        return (*shift > 0 ? 1 : -1);
    }
    else if (dbl_ldbl == 2)
    {
        *shift = exp - 1023; // 1023?
        return (*shift > 0 ? 1 : -1);
    }
}

void    print_float(t_lst *temp, double input)
{
    t_dbl   res;
    unsigned    shift;

    res.origin = input;
    printf("%u\n", res.parts.sign);
    printf("%u\n", res.parts.exp);
    printf("%llu\n", res.parts.mant);
    printf("\nMANT_BINARY\n%s\n", ft_itoa_base(res.parts.mant, 2));
    printf("%s\n", ft_itoa_base(res.parts.exp, 2));
    // print_bit(res.parts.exp, 11);

    // if (exp_shift(res.parts.exp, &shift, 1) > 0) ;
        
}

void    print_lfloat(t_lst *temp, long double input)
{
    t_ldbl  res;
    unsigned    shift;

    res.origin = input;
    printf("%u\n", res.parts.sign);
    printf("%u\n", res.parts.exp);
    printf("%llu\n", res.parts.mant);
    printf("\nMANT_BINARY\n%s\n", ft_itoa_base(res.parts.mant, 2));

    // if (exp_shift(res.parts.exp, &shift, 2) > 0) ;
}