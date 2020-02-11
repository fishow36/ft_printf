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

int print_elem2(t_lst *temp, va_list ap, int *w_p)
{
	if (temp->type == 'c')
		return (print_char(temp, va_arg(ap, int), w_p));
	else if (temp->type == 's')
		return (print_str(temp, va_arg(ap, char*), w_p));
	else if (temp->type == 'p')
		return (print_ptr(temp, va_arg(ap, void*), w_p));
	/*else if (temp->type == 'f')
	{
		if (temp->length[0] == 'L')
			print_lfloat(temp, va_arg(ap, long double));
		else
			print_float(temp, va_arg(ap, double));
	}*/
	else
		return (print_char(temp, temp->type, w_p));
}

int print_elem(t_lst *temp, va_list ap)
{
	int w_p[2];

	w_p[0] = 0; //width
	w_p[1] = -1; // precision
	if (temp->width)
	{
		if (temp->width[0] == '*')
			w_p[0] = va_arg(ap, int);
		else
			w_p[0] = ft_atoi(temp->width);        
	}
	if (temp->precision)
	{
		if (temp->precision[0] == '*')
			w_p[1] = va_arg(ap, int);
		else
			w_p[1] = ft_atoi(temp->precision);        
	}
	if (temp->type == 'd' || temp->type == 'i')
	{
		if (temp->length[0] == 'l' && temp->length[1] != 'l')
			return (print_long(temp, va_arg(ap, long), w_p));            
		else if (temp->length[0] == 'l' && temp->length[1] == 'l')
		{
			return (print_long_long(temp, va_arg(ap, long long), w_p));
		}     
		else if (temp->length[0] == 'h' && temp->length[1] != 'h')
			return (print_short(temp, va_arg(ap, int), w_p));
		else if (temp->length[0] == 'h' && temp->length[1] == 'h')
			return (print_sshort(temp, va_arg(ap, int), w_p));
		else
			return (print_int(temp, (long long)va_arg(ap, int), w_p)); 
	}
		
	else if (temp->type == 'o' || temp->type == 'u'
	|| temp->type == 'x' || temp->type == 'X')
	{
		if (temp->length[0] == 'l' && temp->length[1] != 'l')
			return (print_ulong(temp, va_arg(ap, unsigned long), w_p));
		else if (temp->length[0] == 'l' && temp->length[1] == 'l')
			return (print_ulong_long(temp, va_arg(ap, unsigned long long), w_p));
		else if (temp->length[0] == 'h' && temp->length[1] != 'h')
			return (print_ushort(temp, va_arg(ap, unsigned int), w_p));
		else if (temp->length[0] == 'h' && temp->length[1] == 'h')
			return (print_uint(temp, va_arg(ap, int), w_p));
		else
			return (print_uint(temp, va_arg(ap, unsigned long long), w_p)); 
	}
	else
		return (print_elem2(temp, ap, w_p));
}

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

//	if (strcmp(format, "") == 0)
//		res = 0;
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