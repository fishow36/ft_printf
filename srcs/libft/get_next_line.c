/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrogg <mbrogg@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 20:44:35 by mbrogg            #+#    #+#             */
/*   Updated: 2019/11/19 21:21:25 by mbrogg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Check descriptor and allocate memory for line
**	so we don't know whether memory static or dynamic in line
**	Also there is null for pointer temp in func get_next_line
**	If check is passed the func returns (1), otherwise (0)
*/

static int	check_null(const int fd, char **p_null, char **line)
{
	char test[1];

	*p_null = NULL;
	if (!line)
		return (0);
	if (!(*line = ft_strnew(0)))
		return (0);
	if (fd >= 0 && fd < _SC_OPEN_MAX)
	{
		if (read(fd, test, 0) == -1)
			return (0);
		else
			return (1);
	}
	else
		return (0);
}

/*
**	The func returns new string (size is BUFF_SIZE) to initialize
**	the buf in main func, also there are searching corresponging
**	item of list (head is static) to add new or using old lists
**	Searching is implemented by using descriptor of GNL
*/

static char	*initbuf_search(t_list **head, t_list **list, size_t fd)
{
	t_list	*temp;
	t_list	*prev;

	if (!(*head))
	{
		if (!(*head = ft_lstnew_fd(fd)))
			return (NULL);
		*list = *head;
	}
	else
	{
		temp = *head;
		while (temp)
		{
			if (fd == temp->content_size && (*list = temp))
				return (ft_strnew(BUFF_SIZE));
			prev = temp;
			temp = temp->next;
		}
		if (!(*list = ft_lstnew_fd(fd)))
			return (NULL);
		prev->next = *list;
	}
	return (ft_strnew(BUFF_SIZE));
}

/*
**	It checks the remainer of reading
*/

static char	*check_data_list(char **line, char **content, char *buf)
{
	char	*temp;
	char	*to_free;

	if (!(*content))
		return (NULL);
	else if ((temp = ft_strchr(*content, '\n')))
	{
		*temp = '\0';
		free(*line);
		*line = ft_strdup(*content);
		to_free = *content;
		*content = ft_strdup(temp + 1);
		free(to_free);
		free(buf);
		return (*content);
	}
	else
	{
		free(*line);
		*line = ft_strdup(*content);
		free(*content);
		return (NULL);
	}
}

/*
**	The loop while in main func of GNL project
**	There is parsing of string ('\n') If it has been
**	found -> write the remainer in list->content,
**	otherwise just write buf into the line
**	If there was mistake, the func would return (-1)
**	Otherwise (0)
*/

static	int	loop_gnl(char **buf, char **tp, char **ln, t_list **lt)
{
	if ((*tp = ft_strchr(*buf, '\n')))
	{
		**tp = '\0';
		free((*lt)->content);
		if (!((*lt)->content = (char *)ft_strdup(*tp + 1)))
			return (-1);
	}
	if (!(ft_strjoin_s(ln, *buf)))
		return (-1);
	return (0);
}

/*
**	The main func of GET NEXT LINE project
** 	returnable value is -1, 0, 1
** 	-1	-> 	there must has been fault
** 	0	->	current point in file is ending -> EOF
** 	1	->	the line has been read successfully
*/

int			get_next_line(const int fd, char **line)
{
	static t_list	*hd;
	t_list			*lt;
	size_t			count;
	char			*temp;
	char			*buf;

	if (!(buf = initbuf_search(&hd, &lt, fd)) || !check_null(fd, &temp, line))
		return (-1);
	if ((lt->content = check_data_list(line, (char **)&(lt->content), buf)))
		return (1);
	while ((count = read(fd, buf, BUFF_SIZE)) && !temp)
	{
		buf[count] = '\0';
		if (loop_gnl(&buf, &temp, line, &lt) == -1)
			return (-1);
	}
	if (count)
	{
		buf[count] = '\0';
		if (!(ft_strjoin_s((char **)&(lt->content), buf)))
			return (-1);
	}
	free(buf);
	return ((lt->content || **line != '\0') ? 1 : ft_lstdelone_s(&hd, &lt));
}
