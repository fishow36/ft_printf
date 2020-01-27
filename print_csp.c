#include "ft_printf.h"

void    print_char(t_lst *temp, int c, va_list ap)
{
    char ch;
    int size;
    char *str;
    char filler;
    char side;

    ch = (char)c;
    str = (char*)malloc(sizeof(char) * 2);
    str[0] = ch;
    str[1] = '\0';
    filler = ' ';
    if (temp->width)
    {
        if (temp->width[0] == '*')
            size = va_arg(ap, int);
        else
            size = ft_atoi(temp->width);
        
        str = align_width(str, size, temp);
    }
    ft_putstr(str);
    ft_strdel(&str);
}