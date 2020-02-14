#include "ft_printf.h"

int print_elem3(t_lst *temp, va_list ap, int *w_p)
{
	if (temp->type == 'c')
		return (print_char(temp, va_arg(ap, int), w_p));
	else if (temp->type == 's')
		return (print_str(temp, va_arg(ap, char*), w_p));
	else if (temp->type == 'p')
		return (print_ptr(temp, va_arg(ap, void*), w_p));
	else if (temp->type == 'f')
	{
		if (temp->length[0] == 'L')
			return (print_lfloat(temp, va_arg(ap, long double), w_p));
		else
			return (print_float(temp, va_arg(ap, double), w_p));
	}
	else
		return print_other(temp, w_p);
}

int print_elem2(t_lst *temp, va_list ap, int *w_p)
{
	if (temp->type == 'o' || temp->type == 'u'
	|| temp->type == 'x' || temp->type == 'X')
	{
		if (temp->length[0] == 'l' && temp->length[1] != 'l')
			return (print_ulong(temp, va_arg(ap, unsigned long), w_p));
		else if (temp->length[0] == 'l' && temp->length[1] == 'l')
			return (print_ulong_long(temp, va_arg(ap, unsigned long long), w_p));
		else if (temp->length[0] == 'h' && temp->length[1] != 'h')
			return (print_ushort(temp, va_arg(ap, unsigned int), w_p));
		else if (temp->length[0] == 'h' && temp->length[1] == 'h')
			return (print_usshort(temp, va_arg(ap, unsigned int), w_p));
		else
			return (print_uint(temp, (unsigned long long)va_arg(ap, unsigned int), w_p)); 
	}
	else
		return (print_elem3(temp, ap, w_p));
}

int print_elem1(t_lst *temp, va_list ap, int *w_p)
{
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
	else
		return (print_elem2(temp, ap, w_p));
}

int	width_star(t_lst **temp, va_list ap, int w)
{
	if ((*temp)->width[0] == '*')
	{
		w = va_arg(ap, int);
		if (w < 0)
		{
			w = w * -1;
			(*temp)->flags[2] = '-';
		}
	}
	else
		w = ft_atoi((*temp)->width);
	return (w);
}

int print_elem(t_lst *temp, va_list ap)
{
	int w_p[2];

	w_p[0] = 0;
	w_p[1] = -1;
	if (temp->width)
		w_p[0] = width_star(&temp, ap, w_p[0]);
	if (temp->precision)
	{
		if (temp->precision[0] == '*')
		{
			w_p[1] = va_arg(ap, int);
			if (w_p[1] < 0)
				w_p[1] = -1;
		}
		else
			w_p[1] = ft_atoi(temp->precision);        
	}
	while (temp->stars > 0)
	{
		va_arg(ap, int);
		temp->stars--;
	}
	return (print_elem1(temp, ap, w_p));
}
