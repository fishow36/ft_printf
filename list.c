#include "ft_printf.h"

t_lst *new(int pos)
{
    t_lst *node;

    node = (t_lst*)malloc(sizeof(t_lst));
    node->next = NULL;
    node->pos = pos;
    ft_memcpy((void *)node->flags, (const void*)"?????", 5);
    ft_memcpy((void *)node->length, (const void*)"??", 2);
    return(node);
}

int		lst_push_front(t_lst **head, t_lst *new)
{
	if (!new)
		return (0);
	if (*head)
		new->next = *head;
	*head = new;
	return (1);
}

void	lst_reverse(t_lst **head)
{
	t_lst	*prev;
	t_lst	*cur;
	t_lst	*next;

	prev = NULL;
	cur = NULL;
	next = *head;
	while (next)
	{
		cur = next;
		next = next->next;
		cur->next = prev;
		prev = cur;
	}
	*head = cur;
}
