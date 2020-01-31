#include "ft_printf.h"

void    print_char(t_lst *temp, int c, va_list ap, int *w_p)
{
    char ch;
    char *str;
    char *t;

    if (temp->type == 'c')
    {
        ch = (char)c;
        str = (char*)malloc(sizeof(char) * 2);
        str[0] = ch;
        str[1] = '\0';
    }
    else
    {
        str = ft_itoa(c);
    }
    if (w_p[0] != 0)
    {
        t = str;
        str = align_width(str, w_p[0], temp);
        ft_strdel(&t);
    }
    ft_putstr(str);
    ft_strdel(&str);
}

void    print_str(t_lst *temp, char *str, va_list ap, int *w_p)
{
    char *t;

    if (w_p[1] < ft_strlen(str) && w_p[1] != -1)
    {
        str = shorten_str(str, w_p[1]);
        t = str;
    }
    if (w_p[0] != 0)  
        str = align_width(str, w_p[0], temp);
    ft_putstr(str);
    if (temp->width)
        ft_strdel(&str);
    if (temp->precision)
        ft_strdel(&t);
}