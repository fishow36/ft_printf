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

// unsigned    exp_shift(unsigned exp, unsigned *shift, unsigned dbl_ldbl)
// {
//     if (dbl_ldbl == 1)
//     {
//         *shift = exp - 1023;
//         return (*shift > 0 ? 1 : -1);
//     }
//     else if (dbl_ldbl == 2)
//     {
//         *shift = exp - 1023; // 1023?
//         return (*shift > 0 ? 1 : -1);
//     }
// }

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
}

static char    *ft_dtoa_two(t_ulli value, int shift)
{
	char        *str;
	unsigned	i;
	unsigned	flag;

	i = 0;
	flag = shift < 0 ? -shift : 0; 
	if (value == 0)
		return (ft_strdup("0"));
	if (!(str = (char*)malloc(sizeof(char) * (64 + flag + 1))))
		return (NULL);
	while (value > 0 || i < 64)
	{
		str[i++] = value % 2 + '0';
		value = value / 2;
	}
	while (--flag > 0)
		str[i++] = '0';
	str[i] = '\0';
	ft_strrev(&str);
	return (str);
}

int     ldbl_to_str(t_ldbl *input, int shift)
{
    char    *res;
    char    *frac;
	char	*temp;

	if ((res = ft_dtoa_two(input->parts.mant, shift)) == NULL)
		return (-1);
	if (shift > 0)
	{
		if ((frac = ft_strncpy(frac, res + shift, 64 - shift)) == NULL)
			return (-1);
		temp = res;
		if ((res = ft_strncpy(res, res, shift)) == NULL)
			return (-1);
		free(temp);
	}
	else
		printf("%s\nres minus^^^\n", res);
}

void    print_lfloat(t_lst *temp, long double input)
{
    t_ldbl		res;
    unsigned	shift;
	unsigned	mid_exp;
	size_t		sign;

	mid_exp = 0;
	mid_exp = mid_exp | ((1 << 15) >> 1) - 1;
    res.origin = input;
    printf("%u\n", res.parts.sign);
    printf("%d\n", (int)res.parts.exp - mid_exp);
    printf("%llu\n", res.parts.mant);
    printf("\nMANT_BINARY\n");
	printf("%s\n", ft_itoa_base(res.parts.mant, 2));
    
	ldbl_to_str(&res, res.parts.exp - mid_exp);
}