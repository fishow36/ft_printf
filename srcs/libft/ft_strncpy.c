/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrogg <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 19:58:37 by mbrogg            #+#    #+#             */
/*   Updated: 2019/09/14 19:58:38 by mbrogg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t n)
{
	size_t	count;

	count = 0;
	while (src[count] != '\0' && count < n)
	{
		dst[count] = src[count];
		count++;
	}
	while (count < n)
		dst[count++] = '\0';
	return (dst);
}
