/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrogg <mbrogg@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 21:44:02 by mbrogg            #+#    #+#             */
/*   Updated: 2019/11/08 08:58:45 by mbrogg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew_fd(size_t fd)
{
	t_list	*res;

	res = (t_list *)malloc(sizeof(t_list));
	if (!res)
		return (NULL);
	res->content = (void *)ft_strnew(0);
	if (!res->content)
	{
		free(res);
		return (NULL);
	}
	res->content_size = fd;
	res->next = NULL;
	return (res);
}
