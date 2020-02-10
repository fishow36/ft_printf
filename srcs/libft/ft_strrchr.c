/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrogg <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 19:58:24 by mbrogg            #+#    #+#             */
/*   Updated: 2019/09/14 19:58:25 by mbrogg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*str;
	char	ch;
	char	*s_res;

	s_res = NULL;
	str = (char *)s;
	ch = (char)c;
	if (ch == '\0')
		return (str + ft_strlen(s));
	while (*str != '\0')
	{
		if (*str == ch)
			s_res = str;
		str++;
	}
	if (s_res)
		return (s_res);
	return (NULL);
}
