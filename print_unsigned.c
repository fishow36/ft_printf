#include "ft_printf.h"

void    print_uint(t_lst *temp, unsigned long long nbr, int *w_p)
{
    char    *str;
    char    flag[2];

    if (temp->length[0] != 'l' && nbr > 4294967295)
        str = ft_strdup("0");
    else if (temp->type == 'u')
        str = ft_itoa_base(nbr, 10);
    else if (temp->type == 'o')
        str = ft_itoa_base(nbr, 8);
    else if (temp->type == 'X' || temp->type == 'x')
    {
        str = ft_itoa_base(nbr, 16);
        if (temp->type == 'x')
            change_case(&str);
    }
    if (temp->flags[2] == '-' || (w_p[0] != 0 && w_p[1] != -1))
        temp->flags[0] = '?';

    if (w_p[1] != -1)
	{
		if ((int)ft_strlen(str) < w_p[1])
		{
			flag[0] = temp->flags[0];
			flag[1] = temp->flags[2];
			temp->flags[2] = '?';
			temp->flags[0] = '0';
			str = int_width(str, w_p[1], temp);
			temp->flags[0] = flag[0];
			temp->flags[2] = flag[1];
		}
        if (temp->flags[4] == '#')
            str = add_zero(str, temp->type, w_p[1]);
	}
    if (w_p[0] != 0)
    {
        if (w_p[1] != -1)
        {
            str = int_width(str, w_p[0], temp);
        }
        else
        {
            if (temp->flags[0] == '0')
            {
                if (temp->type == 'x' || temp->type == 'X')
                    w_p[0] = w_p[0] - 2;
                else if (temp->type == 'o')
                    w_p[0]--;
                str = int_width(str, w_p[0], temp);
                str = add_zero(str, temp->type, w_p[1]);
            }
            else
            {
                str = add_zero(str, temp->type, w_p[1]);
                str = int_width(str, w_p[0], temp);
            }
        }
    }
    if (w_p[0] == 0 && w_p[1] == -1 && temp->flags[4] == '#')
        str = add_zero(str,temp->type, w_p[1]);
    ft_putstr(str);
}

void	print_ulong(t_lst *temp, unsigned long nbr, int *w_p)
{
	print_uint(temp, (unsigned long long)nbr, w_p);
}

void	print_ulong_long(t_lst *temp, unsigned long long nbr, int *w_p)
{
	print_uint(temp, nbr, w_p);
}

void	print_ushort(t_lst *temp, unsigned int nbr, int *w_p)
{
	print_uint(temp, (unsigned long long)nbr, w_p);
}
