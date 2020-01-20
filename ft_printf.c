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

int count_args(const char *format)
{
    int i;
    int amount;

    i = 0;
    amount = 0;
    while (format[i])
    {
        if (format[i] == '%' && format[i + 1] != '%'
        && is_even(format, i) == 1)
            amount++;
        i++;
    }
    return (amount);
}

int ft_printf(const char *format, ...)
{
    va_list ap;
    int i;
    char *str;
    char *str2;
    int expected_amount;

    va_start(ap, format);
    i = 0;
    expected_amount = count_args(format);
    return(0);
}