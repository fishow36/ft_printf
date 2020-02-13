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
	int         flag;

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

t_ulli  ft_power(unsigned num)
{
    t_ulli      res_llu;

    res_llu = 1;
    while (num-- > 0)
    {
        res_llu *= 2;
    }
    return (res_llu);
}

char    *print_ldbl_dec(char *i_part, char *f_part)
{
    int         power;
    unsigned    len;
    t_ulli      i_res;
    long double f_res;

    power = ft_strlen(i_part);
    len = power;
    i_res = 0;
    f_res = 0.0;
    if (f_part == NULL)
    {
	    printf("%s\n", i_part);
    }
    else
    {
        // printf("%s\n", i_part);
        // printf("%s\n", f_part);
        while (--power >= 0)
        {
            if (i_part[power] == '1')
                i_res += ft_power(len - power - 1);
        }
        len = ft_strlen(f_part);
        power = 0;
        while (power < len)
        {
            if (f_part[power] == '1')
                f_res += 1. / ft_power(power + 1);
            power++;
        }
        printf("%llu\n", i_res);    
        printf("%Lf\n", f_res);
    }
}

int     ldbl_to_str(t_ldbl *input, int shift)
{
    char    *i_part;
    char    *f_part;
	char	*temp;

	f_part = NULL;
    if ((i_part = ft_dtoa_two(input->parts.mant, shift)) == NULL)
		return (-1);
	if (shift > 0)
	{
		if (!(f_part = ft_strncpy(f_part, i_part + shift + 1, 64 - shift - 1)))
			return (-1);
		temp = i_part;
		if ((i_part = ft_strncpy(i_part, i_part, shift + 1)) == NULL)
			return (-1);
		free(temp);
	}

    print_ldbl_dec(i_part, f_part);
}

char    *lfloat(long double input)
{
    char        *output;
    t_ldbl		res;
    unsigned	shift;
	unsigned	mid_exp;
	size_t		sign;
    t_lan       mant_lan;

	mid_exp = 0;
    output = NULL;
	mid_exp = mid_exp | ((1 << 15) >> 1) - 1;
    res.origin = input;
    printf("ep mid -> %llu\n", mid_exp);
    printf("%u\n", res.parts.sign);
    // printf("%d\n", (int)res.parts.exp - mid_exp);
    printf("%d\n", res.parts.exp);
    printf("%llu\n\n", res.parts.mant);

    // printf("\nMANT_BINARY\n");
	// printf("%s\n", ft_itoa_base(res.parts.mant, 2));
    
	// ldbl_to_str(&res, res.parts.exp - mid_exp);

    // mant_lan = create_lan(res.parts.mant);
    // print_lan(mant_lan);

    print_lan(neg_power_lan(res.parts.mant, res.parts.exp));

    return (output);
}

void    print_lfloat(t_lst *temp, long double input)
{
    lfloat(input);
}