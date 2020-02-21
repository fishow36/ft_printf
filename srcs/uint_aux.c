/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   uint_aux.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshor <eshor@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 13:10:43 by eshor             #+#    #+#             */
/*   Updated: 2020/02/21 13:39:46 by eshor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*create_str_u(unsigned long long nbr, t_lst **temp, int *w_p, char *fl)
{
	char *str;

	if (nbr == 0 && w_p[1] == 0 && !((*temp)->type == 'o' &&
	(*temp)->flags[4] == '#'))
		str = ft_strdup("");
	else if ((*temp)->length[0] != 'l' && nbr > 4294967295 &&
	(*temp)->type != 'p' && (*temp)->length[0] != '?')
		str = ft_strdup("0");
	else if ((*temp)->type == 'u')
		str = ft_itoa_base(nbr, 10);
	else if ((*temp)->type == 'o')
		str = ft_itoa_base(nbr, 8);
	else
	{
		str = ft_itoa_base(nbr, 16);
		if ((*temp)->type == 'X')
			change_case(&str);
		else if ((*temp)->type == 'p')
		{
			(*temp)->type = 'x';
			*fl = 'p';
		}
	}
	return (str);
}

void	prec_u(char **str, t_lst *temp, int *w_p)
{
	char flag[2];

	flag[0] = temp->flags[0];
	flag[1] = temp->flags[2];
	if ((int)ft_strlen(*str) < w_p[1])
	{
		temp->flags[2] = '?';
		temp->flags[0] = '0';
		*str = int_width(*str, w_p[1], temp);
		temp->flags[0] = flag[0];
		temp->flags[2] = flag[1];
	}
}

void	width_u(char **str, t_lst *temp, int *w_p, t_ulli nbr)
{
	if (w_p[1] > 0)
		*str = int_width(*str, w_p[0], temp);
	else
	{
		if (temp->flags[0] == '0')
		{
			if (temp->flags[4] == '#' && nbr != 0)
			{
				if (temp->type == 'x' || temp->type == 'X')
					w_p[0] = w_p[0] - 2;
				else if (temp->type == 'o')
					w_p[0]--;
			}
			*str = int_width(*str, w_p[0], temp);
		}
		if (temp->flags[4] == '#' && nbr != 0)
		{
			if ((int)ft_strlen(*str) != 0)
				*str = add_zero(*str, temp->type, -1);
			*str = int_width(*str, w_p[0], temp);
		}
		else
			*str = int_width(*str, w_p[0], temp);
	}
}
