/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   width.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshor <eshor@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/02 18:10:55 by eshor             #+#    #+#             */
/*   Updated: 2020/02/11 17:44:53 by eshor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char *shorten_str(char *str, int precision)
{
    char *res;
    int i;

    i = 0;
    if (!(res = (char*)malloc(sizeof(precision + 1))))
        return (NULL);
    res[precision] = '\0';
    while (i < precision)
    {
        res[i] = str[i];
        i++;
    }
    ft_strdel(&str);
    return (res);
}

void    int_left(char **res, char *str,  int size, char filler)
{
    int i;

    i = 0;
    while (str[i])
    {
        (*res)[i] = str[i];
        i++;
    }
    while (i < size)
    {
       (*res)[i] = filler;
        i++;
    }
    (*res)[i] = '\0';
}

int     right_finish(int j, char **res, char *str, int i)
{
    while(str[j])
    {
        (*res)[i] = str[j];
        i++;
        j++;
    }
    return (i);
}

void    int_right(char **res, char *str, int size, t_lst *node)
{
    int i;
    int j;
    int len;
    char filler;

    len = ft_strlen(str);
    i = 0;
    filler = ' ';
    if (node->flags[0] == '0')
        filler = '0';
    if (str[0] == '-' && node->flags[0] == '0')
    {
        (*res)[0] = '-';
        i = 1;
        len--;
    }
    while (i < size - len)
    {
        (*res)[i] = filler;
        i++;
    }
    j = ft_strlen(str) - len;
    i = right_finish(j, res, str, i);
    (*res)[i] = '\0';
}

char *int_width(char *str, int size, t_lst *node)
{
    char *res;
    char filler;

    if (!(res = (char*)malloc(sizeof(char) * (size + 1))))
        return (NULL);
    filler = ' ';
    if (node->flags[0] == '0')
        filler = '0';
    if (node->flags[2] == '-')
        int_left(&res, str, size, filler);
    else
        int_right(&res, str, size, node);
    ft_strdel(&str);
    return (res);
}