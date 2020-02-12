/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshor <eshor@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 20:18:28 by mbrogg            #+#    #+#             */
/*   Updated: 2020/02/11 18:08:13 by eshor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int    print_from_list(const char *format, t_lst *head, va_list ap)
{
	t_lst *temp;
	int i;
	int res;

	temp = head;
	i = 0;
	res = 0;
	while (temp)
	{
		while (i < temp->pos)
		{
			ft_putchar(format[i]);
			i++;
			res++;
		}
		res += print_elem(temp, ap);
		i = temp->next_pos;
		temp = temp->next;
	}
	while (format[i])
	{
		ft_putchar(format[i]);
		i++;
		res++;
	}
	return (res);
}

int    ft_printf(const char *format, ...)
{
	va_list ap;
	int *pos;
	int amount;
	t_lst *head;
	t_lst *temp;
	int res;

	amount = 0;
	va_start(ap, format);
	pos = count_args(format, &amount);
	res = 0;
	if (amount != 0)
	{
		head = create_list(format, pos, amount);
		temp = head;
		/*while (head)
		{
			print_node(head);
			head = head->next;
		}*/
		res = print_from_list(format, temp, ap);
	}
	else
	{
		ft_putstr(format);
		res = (int)ft_strlen(format);
	} 
	va_end(ap);
	if (amount != 0)
		lst_del(&head);
	free(pos);
	return(res);
}