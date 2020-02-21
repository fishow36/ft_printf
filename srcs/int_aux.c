/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_aux.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshor <eshor@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 13:03:50 by eshor             #+#    #+#             */
/*   Updated: 2020/02/20 23:51:46 by eshor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	add_s_or_p(char **str, t_lst *temp, long long int nbr)
{
	
	if (temp->flags[1] == '+' && nbr >= 0)
		*str = add_plus(*str, '+');
	else if (temp->flags[3] == ' ' && nbr >= 0)
		*str = add_plus(*str, ' ');
}

void	zero_flag(char **str, long long int nbr, t_lst *temp, int *w_p)
{
	*str = int_width(*str, w_p[0], temp);
	if (nbr < 0)
		(*str)[0] = '-';
	else if (temp->flags[1] == '+' && nbr >= 0)
		(*str)[0] = '+';
	else if (temp->flags[3] == ' ')
		(*str)[0] = ' ';
}

void	prec_greater(char **str, t_lst **temp, int *w_p)
{
	char flag[2];

	flag[0] = (*temp)->flags[0];
	flag[1] = (*temp)->flags[2];
	(*temp)->flags[2] = '?';
	(*temp)->flags[0] = '0';
	if ((*str)[0] == '-')
		*str = int_width(*str, w_p[1] + 1, *temp);
	else
		*str = int_width(*str, w_p[1], *temp);
	(*temp)->flags[0] = flag[0];
	(*temp)->flags[2] = flag[1];
}

void	prec_no_width(char **str, t_lst *temp, long long int nbr, int *w_p)
{
	if (temp->flags[2] == '-')
	{
		temp->flags[0] = '?';
		add_s_or_p(str, temp, nbr);
		*str = int_width(*str, w_p[0], temp);
	}
	else
	{
		if (temp->flags[0] == '0')
			zero_flag(str, nbr, temp, w_p);
		else
		{
			add_s_or_p(str, temp, nbr);
			*str = int_width(*str, w_p[0], temp);
		}
	}
}
