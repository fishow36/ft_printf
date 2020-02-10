/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrogg <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 19:59:17 by mbrogg            #+#    #+#             */
/*   Updated: 2019/09/14 19:59:18 by mbrogg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *dest, const char *src)
{
	size_t	count;
	size_t	len_dest;

	len_dest = ft_strlen(dest);
	count = 0;
	while (src[count] != '\0')
	{
		dest[len_dest + count] = src[count];
		count++;
	}
	dest[len_dest + count] = '\0';
	return (dest);
}
