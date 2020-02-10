/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrogg <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 21:25:14 by mbrogg            #+#    #+#             */
/*   Updated: 2019/09/07 21:25:15 by mbrogg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*p_dst;
	const unsigned char	*p_src;

	p_dst = (unsigned char *)dst;
	p_src = (unsigned char *)src;
	if (!dst && !src)
		return (NULL);
	if (p_dst < p_src)
		while (len--)
			*p_dst++ = *p_src++;
	else
	{
		p_dst += len;
		p_src += len;
		while (len--)
			*--p_dst = *--p_src;
	}
	return (dst);
}
