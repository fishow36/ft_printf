/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_other.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshor <eshor@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 13:08:36 by eshor             #+#    #+#             */
/*   Updated: 2020/02/17 13:09:01 by eshor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		print_other(t_lst *temp, int *w_p)
{
	if (temp->type == 0)
		return (0);
	else
		return (print_char(temp, temp->type, w_p));
}
