#include "ft_printf.h"

int is_even(const char *format, int i)
{
    int amount;

    amount = 0;
    i--;
    while (format[i] && format[i] == '%')
    {
        if (format[i] == '%')
            amount++;
        i--;
    }
    if (amount % 2 == 0)
        return (1);
    else
        return (0);    
}

char    *count_args(const char *format, int *amount)
{
    int i;
    int j;
    char *c;

    i = -1;
    while (format[++i])
        if (format[i] == '%' && format[i + 1] != '%'
        && is_even(format, i) == 1 && format[i + 1] != '\0')
            (*amount)++;
    c = (char*)malloc(sizeof(char) * (*amount + 1));
    i = -1;
    j = 0;
    while (format[++i])
    {
        if (format[i] == '%' && format[i + 1] != '%'
        && is_even(format, i) == 1 && format[i + 1] != '\0')
            {
                c[j] = format[i + 1];
                j++;
            }
    }
    c[j] = '\0';
    
    return (c);
}

int     ft_printf(const char *format, ...)
{
    va_list ap;
    int i;
    char *conversions;
    int expected_amount;

    expected_amount = 0;
    conversions = count_args(format, &expected_amount);
//    va_start(ap, format);
    i = 0;
    printf("%s\n", conversions);
    printf("%d\n", expected_amount);
    return(0);
}