/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrogg <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 16:59:47 by mbrogg            #+#    #+#             */
/*   Updated: 2019/09/07 16:59:48 by mbrogg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	a;
	unsigned char	*point;

	a = (unsigned char)c;
	point = (unsigned char *)b;
	while (len--)
		*point++ = a;
	return (b);
}
