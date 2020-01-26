/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrogg <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 10:54:08 by mbrogg            #+#    #+#             */
/*   Updated: 2019/09/17 10:54:10 by mbrogg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*res;
	t_list	*temp;
	t_list	*last;

	res = lst;
	temp = NULL;
	last = NULL;
	if (!lst || !f)
		return (NULL);
	while (lst)
	{
		temp = lst->next;
		lst = f(lst);
		if (!lst)
			return (NULL);
		lst->next = temp;
		if (last)
			last->next = lst;
		else
			res = lst;
		last = lst;
		lst = lst->next;
	}
	return (res);
}
