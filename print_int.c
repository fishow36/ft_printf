#include "ft_printf.h"

void    print_int(t_lst *temp, int nbr, va_list ap, int *w_p)
{
	char *str;
	int i;
	char *t;
	char flag[2];

	str = ft_itoa(nbr);
	if (w_p[1] != -1)
	{
		str = ft_itoa(nbr);
		if (ft_strlen(str) < w_p[1])
		{
			flag[0] = temp->flags[0];
			flag[1] = temp->flags[2];
			temp->flags[2] = '?';
			temp->flags[0] = '0';
			if (nbr < 0)
				str = int_width(str, w_p[1] + 1, temp);
			else
				str = int_width(str, w_p[1], temp);
			temp->flags[0] = flag[0];
			temp->flags[2] = flag[1];
		}
		if (temp->flags[1] == '+' && nbr >= 0)
			str = add_plus(str, '+');
		else if (temp->flags[3] == ' ' && nbr >= 0)
			str = add_plus(str, ' ');
	}	
	if (w_p[0] != 0 && w_p[0] > ft_strlen(str))
	{
		if (w_p[1] != -1)
		{
			temp->flags[0] = '?';
			temp->flags[1] = '?';
			temp->flags[3] = '?';
			str = int_width(str, w_p[0], temp);
		}
		else
		{
			if (temp->flags[2] == '-' && temp->flags[3] == ' ')
			{
				if (nbr >= 0)
					str = add_plus(str, ' ');
				str = int_width(str, w_p[0], temp);
			}
			else if (temp->flags[2] != '-')
			{
				if (temp->flags[0] == '0')
				{
					str = int_width(str, w_p[0], temp);
					if (nbr < 0)
						str[0] = '-';
					else if (temp->flags[1] == '+' && nbr >= 0)
						str[0] = '+';
					else if (temp->flags[3] == ' ')
						str[0] = ' ';
				}
				else
				{
					if (temp->flags[1] == '+' && nbr >= 0)
						str = add_plus(str, '+');
					else if (temp->flags[3] == ' ')
						str = add_plus(str, ' ');
					str = int_width(str, w_p[0], temp);
				}
			}
		}
	}
	else
	{
		if (temp->flags[1] == '+' && nbr >= 0)
			str = add_plus(str, '+');
		else if (temp->flags[3] == ' ' && nbr >= 0)
			str = add_plus(str, ' ');
	}
	ft_putstr(str);
	ft_strdel(&str);
}