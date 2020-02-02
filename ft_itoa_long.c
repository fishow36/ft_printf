/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_long.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshor <eshor@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/02 17:05:45 by eshor             #+#    #+#             */
/*   Updated: 2020/02/02 18:08:33 by eshor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		nbr_len(long long n)
{
	int len;

	len = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		n = n * -1;
		len++;
	}
	while (n > 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

static char		*check_excep(long long n)
{
	char *result;

	if (n == 0)
		result = ft_strdup("0");
	else
		result = (ft_strdup("-9223372036854775808"));
	return (result);
}

char			*ft_itoa_long(long long n)
{
	char	*result;
	int		len;
	int		sign;

	sign = 1;
	len = nbr_len(n);
	if (n == 0 || n == -9223372036854775808)
		return (check_excep(n));
	if (n < 0)
	{
		n = n * -1;
		sign = -1;
	}
	if (!(result = ft_strnew(len)))
		return (NULL);
	if (sign == -1)
		result[0] = '-';
	while (n > 0)
	{
		result[--len] = (char)(n % 10 + '0');
		n = n / 10;
	}
	return (result);
}
