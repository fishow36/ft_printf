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

char *align_width(char *str, int size, t_lst *node)
{
    char *res;
    int i;
    int j;
    char filler;
    char side;

    if (!(res = (char*)malloc(sizeof(char) * (size + 1))))
        return (NULL);
    i = 0;
    filler = ' ';
    side = 'r';
    if(node->flags[0] == '0')
        filler = '0';
    if (node->flags[2] == '-')
        side = 'l';
    if (side == 'l')
    {
        while(str[i])
        {
            res[i] = str[i];
            i++;
        }
        while (i < size)
        {
            res[i] = filler;
            i++;
        }
    }
    else
    {
        while (i < size - (int)ft_strlen(str))
        {
            res[i] = filler;
            i++;
        }
        j = 0;
        while (i < size)
        {
            res[i] = str[j];
            i++;
            j++;
        }
    }
    res[i] = '\0';
    ft_strdel(&str);
    return (res);
}

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

char *int_width(char *str, int size, t_lst *node)
{
    char *res;
    int i;
    int j;
    int len;
    char filler;

    if (!(res = (char*)malloc(sizeof(char) * (size + 1))))
        return (NULL);
    len = ft_strlen(str);
    i = 0;
    filler = ' ';
    if (node->flags[0] == '0')
        filler = '0';
    if (str[0] == '-' && node->flags[0] == '0')
    {
        res[0] = '-';
        i = 1;
        len--;
    }
    if (node->flags[2] == '-')
    {
        while (str[i])
        {
            res[i] = str[i];
            i++;
        }
        while (i < size)
        {
            res[i] = filler;
            i++;
        }
    }
    else
    {
        while (i < size - len)
        {
            res[i] = filler;
            i++;
        }
        j = ft_strlen(str) - len;
        while(str[j])
        {
            res[i] = str[j];
            i++;
            j++;
        }
    }
    res[i] = '\0';
    ft_strdel(&str);
    return (res);
}