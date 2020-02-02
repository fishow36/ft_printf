#include "ft_printf.h"

int     is_even(const char *format, int i)
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

void    change_case(char **str)
{
    int i;

    i = 0;
    while ((*str)[i])
    {
        if ((*str)[i] >= 'A' && (*str)[i] <= 'F')
            (*str)[i] += 32;
        i++;
    }
}
