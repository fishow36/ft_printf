/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrogg <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 20:01:38 by mbrogg            #+#    #+#             */
/*   Updated: 2019/09/07 20:01:39 by mbrogg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char		*p_dst;
	const unsigned char	*p_src;

	p_dst = (unsigned char *)dst;
	p_src = (unsigned char *)src;
	if (!dst && !src)
		return (NULL);
	while (n--)
		*p_dst++ = *p_src++;
	return (dst);
}
