/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrogg <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 17:08:34 by mbrogg            #+#    #+#             */
/*   Updated: 2019/09/15 17:08:35 by mbrogg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*res;
	char	*dup;
	char	*temp;
	size_t	len;

	if (!s)
		return (NULL);
	dup = ft_spaces((char *)s);
	if (*dup == '\0')
	{
		if (!(res = (char *)malloc(sizeof(char))))
			return (NULL);
		*res = '\0';
		return (res);
	}
	temp = ft_spaces_rev(dup + ft_strlen(dup) - 1);
	if (!(res = ft_strnew(temp - dup)))
		return (NULL);
	len = 0;
	while (dup != temp)
		res[len++] = *dup++;
	res[len] = '\0';
	return (res);
}
