/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   long_arithm.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrogg <mbrogg@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 11:46:34 by mbrogg            #+#    #+#             */
/*   Updated: 2020/02/13 12:45:35 by mbrogg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// lan - long arith num

char    *creat_str_and_count(t_ulli input_num, size_t *len, int *len_str)
{
    char    *res;
    t_ulli  cpy;
    int     counter;

    *len = 0;
    *len_str = 0;
    cpy = input_num;
    while(cpy > 0)
    {
        (*len_str)++;
        cpy /= 10;
    }
    res = (char *)malloc(sizeof(char) * (*len_str + 1));
    counter = *len_str - 1;
    while (counter >= 0)
    {
        res[counter--] = input_num % 10 + '0';
        input_num /= 10;
    }
    res[*len_str] = '\0';
    *len = (*len_str) / 4 + (*len_str) % 4;
    return (res);
}

int		ft_atoi_lan(char *str)
{
    unsigned long	res;
    int             counter;
    char            *s;

    counter = 0;
	s = str;
	res = 0;
	while (ft_isdigit(*s) && counter < 4 && *s != '\0')
    {       
        counter++;
        s++;
    }
	while (counter-- >= 0)
        res = res * 10 + (*s--) - '0';
    printf("INT %d\n", (int)res);
    // return ((int)res);
    return (0);
}


t_lan   create_lan(t_ulli input_num)
{
    t_lan   res;
    int     count;
    int     i;
    char    *str;
    int     len_str;

    count = 1;
    i = 0;
    str = creat_str_and_count(input_num, &res.len, &len_str);
    res.num = (int *)malloc(sizeof(int) * res.len);
    printf("\n!!!res -> %s\n%zu\n\n", str, res.len);
    while(--len_str >= 0)
    {
        if (count == 4 || str[i] == '\0')
        {
            res.num[i / 4] = ft_atoi(str + i - count);
            count = 1;
        }
        count++;
        i++;
    }
    return (res);
}

// void    print_lan()
