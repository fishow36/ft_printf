/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrogg <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 19:58:34 by mbrogg            #+#    #+#             */
/*   Updated: 2019/09/14 19:58:36 by mbrogg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*res;
	size_t	i;

	i = 0;
	if (!(res = (char *)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	else
		while (i < size + 1)
			res[i++] = '\0';
	return (res);
}
