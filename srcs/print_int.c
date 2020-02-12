/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshor <eshor@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/02 18:10:46 by eshor             #+#    #+#             */
/*   Updated: 2020/02/11 18:18:13 by eshor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int    print_int(t_lst *temp, long long int nbr, int *w_p)
{
	char *str;
	char flag[2];
	int len;

	str = ft_itoa_long(nbr);
	if (nbr == 0 && w_p[1] == 0)
        str = ft_strdup("");
	len = (nbr < 0) ? (int)ft_strlen(str) - 1 : (int)ft_strlen(str);
	if (w_p[1] != -1)
	{
		if (len < w_p[1])
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
		{
			str = add_plus(str, '+');
			temp->flags[1] = '?';
		}
			
		else if (temp->flags[3] == ' ' && nbr >= 0)
		{
			str = add_plus(str, ' ');
			temp->flags[3] = '?';
		}
	}	
	if (w_p[0] != 0 && w_p[0] > (int)ft_strlen(str))
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
			if (temp->flags[2] == '-')
			{
				temp->flags[0] = '?';
				if (temp->flags[1] == '+')
				{
					if (nbr >= 0)
						str = add_plus(str, '+');	
				}
				else if (temp->flags[3] == ' ')
				{
					if (nbr >= 0)
						str = add_plus(str, ' ');
				}
				
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
	len = (int)ft_strlen(str);
	ft_strdel(&str);
	return (len);
}

int	print_long(t_lst *temp, long nbr, int *w_p)
{
	return(print_int(temp, (long long)nbr, w_p));
}

int	print_long_long(t_lst *temp, long long nbr, int *w_p)
{
	return(print_int(temp, (long long)nbr, w_p));
}

int	print_short(t_lst *temp, int nbr, int *w_p)
{
	short num;

	num = (short)nbr;
	return(print_int(temp, (long long)num, w_p));
}

int	print_sshort(t_lst *temp, int nbr, int *w_p)
{
	char num;

	num = (char)nbr;
	return(print_int(temp, (long long)num, w_p));
}
