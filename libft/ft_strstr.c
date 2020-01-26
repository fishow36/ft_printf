/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrogg <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 19:58:21 by mbrogg            #+#    #+#             */
/*   Updated: 2019/09/14 19:58:23 by mbrogg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	char	*str1;
	char	*str2;
	char	*res;

	res = NULL;
	str1 = (char *)big;
	if (!(ft_strlen(little)))
		return (str1);
	while (*str1 != '\0')
	{
		res = str1;
		str2 = (char *)little;
		while (*str1 == *str2++ && *str1 != '\0')
			str1++;
		if (*(str2 - 1) == '\0')
			return (res);
		str1 = res + 1;
	}
	return (NULL);
}
