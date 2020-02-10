/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_s.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrogg <mbrogg@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 16:50:21 by mbrogg            #+#    #+#             */
/*   Updated: 2019/11/08 11:20:26 by mbrogg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_strjoin_s(char **str, char *buf)
{
	char	*pointer;

	pointer = *str;
	*str = ft_strjoin((char *)*str, buf);
	free(pointer);
	if (!(*str))
		return (0);
	return (1);
}
