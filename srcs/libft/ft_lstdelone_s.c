/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone_s.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrogg <mbrogg@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 10:53:59 by mbrogg            #+#    #+#             */
/*   Updated: 2019/11/07 11:05:29 by mbrogg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_lstdelone_s(t_list **head, t_list **alst)
{
	t_list	*temp;

	if (head && *head)
	{
		temp = *head;
		if (*head != *alst)
		{
			while (temp->next != *alst)
				temp = temp->next;
		}
		temp->next = (*alst)->next;
		free((*alst)->content);
		free(*alst);
		if (*head == *alst)
			*head = NULL;
		*alst = NULL;
	}
	return (0);
}
