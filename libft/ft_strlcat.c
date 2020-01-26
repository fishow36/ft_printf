/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrogg <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 19:58:52 by mbrogg            #+#    #+#             */
/*   Updated: 2019/09/14 19:58:53 by mbrogg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	res;
	size_t	len_d;

	len_d = ft_strlen(dst);
	res = dstsize + ft_strlen(src);
	if (!dst || !src)
		return (res);
	if (len_d < dstsize)
	{
		dst += len_d;
		res = res - dstsize + len_d;
		dstsize -= len_d;
		while (dstsize-- > 1 && *src)
			*dst++ = *src++;
		*dst = '\0';
	}
	return (res);
}
