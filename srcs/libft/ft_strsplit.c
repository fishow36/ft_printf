/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrogg <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 17:53:42 by mbrogg            #+#    #+#             */
/*   Updated: 2019/09/15 17:53:43 by mbrogg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	size_t	ft_count_words(char *s, char ch)
{
	size_t	res;

	res = 0;
	while (*s != '\0')
	{
		if (*s != ch)
		{
			res++;
			while (*s != ch && *s != '\0')
				s++;
			s--;
		}
		s++;
	}
	return (res);
}

static	char	*ft_spaces_ch(char *s, char ch)
{
	while (*s == ch && *s != '\0')
		s++;
	return (s);
}

static	size_t	ft_strlen_ch(char *s, char c)
{
	size_t	len;

	len = 0;
	while (*s != c && *s != '\0')
	{
		s++;
		len++;
	}
	return (len);
}

static	char	*ft_strcpy_ch(char *s1, char **s2, char c)
{
	while (**s2 != c && **s2 != '\0')
	{
		*s1++ = **s2;
		(*s2)++;
	}
	*s1 = '\0';
	return (s1);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**res;
	char	*temp;
	size_t	i;

	i = 0;
	temp = (char *)s;
	if (!s)
		return (NULL);
	if (!(res = (char **)malloc(sizeof(char *) *
		(ft_count_words(temp, c) + 1))))
		return (NULL);
	while (*temp != '\0')
	{
		temp = ft_spaces_ch(temp, c);
		if (*temp == '\0')
			break ;
		*(res + i) = (char *)malloc(sizeof(char) * (1 + ft_strlen_ch(temp, c)));
		if (!(*(res + i)))
			return (ft_free_split(res, i));
		ft_strcpy_ch(*(res + i++), &temp, c);
	}
	*(res + i) = NULL;
	return (res);
}
