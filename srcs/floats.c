#include "ft_printf.h"

int    print_float(t_lst *temp, double input, int *w_p)
{
    return (print_lfloat(temp, (long double)input, w_p));
}

void    add_sorp_fl(t_lst *temp, char **str)
{
    if (temp->flags[1] == '+' && (*str)[0] != '-')
        *str = add_plus(*str, '+');
    else if (temp->flags[3] == ' ' && (*str)[0] != '-')
        *str = add_plus(*str, ' ');
}

int    print_lfloat(t_lst *temp, long double input, int *w_p)
{
    char    *str;
    int     len;

    str = ft_strdup("10.205000");
    if (w_p[0] > (int)ft_strlen(str))
    {
        if (temp->flags[2] == '-' || (temp->flags[2] != '-' && temp->flags[0] != '0'))
        {
            add_sorp_fl(temp, &str);
            str = int_width(str, w_p[0], temp);
        }
        else if (temp->flags[0] == '0')
        {
            str = int_width(str, w_p[0], temp);
            if (input < 0)
                str[0] = '-';
            else if (temp->flags[1] == '+' && input >= 0)
                str[0] = '+';
            else if (temp->flags[3] == ' ')
                str[0] = ' ';
        }
    }
    ft_putstr(str);
    len = (int)ft_strlen(str);
    ft_strdel(&str);
    return (len);
}