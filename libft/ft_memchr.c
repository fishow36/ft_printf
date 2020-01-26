/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrogg <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 21:48:57 by mbrogg            #+#    #+#             */
/*   Updated: 2019/09/14 19:56:31 by mbrogg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*point;
	unsigned char		symb;

	point = (unsigned char *)s;
	symb = (unsigned char)c;
	while (n--)
	{
		if (*point == symb)
			return ((void *)point);
		point++;
	}
	return (NULL);
}
