/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrogg <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 19:58:46 by mbrogg            #+#    #+#             */
/*   Updated: 2019/09/14 19:58:48 by mbrogg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *dest, const char *src, size_t n)
{
	size_t	count;
	size_t	len_dest;

	len_dest = ft_strlen(dest);
	count = 0;
	while (src[count] != '\0' && count < n)
	{
		dest[len_dest + count] = src[count];
		count++;
	}
	dest[len_dest + count] = '\0';
	return (dest);
}
