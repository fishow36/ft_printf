/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   long_arithm.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrogg <mbrogg@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 11:46:34 by mbrogg            #+#    #+#             */
/*   Updated: 2020/02/13 15:18:09 by mbrogg           ###   ########.fr       */
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

int		ft_atoi_lan(char *str, int index)
{
    unsigned long	res;
    int             counter;

	res = 0;
    if (index > 3)
        counter = index - 3;
    else
        counter = 0;
	while (counter <= index)
        res = res * 10 + str[counter++] - '0';
    // printf("lan %d\n", (int)res);
    return ((int)res);
}

void    print_lan(t_lan to_print)
{
    int counter;

    counter = 0;
    while (counter < to_print.len)
        printf("%d ", to_print.num[counter++]);
    printf("\n");
}

t_lan   create_lan(t_ulli input_num)
{
    t_lan   res;
    int     i;
    int     count;
    char    *str;
    int     len_str;

    int temp;

    count = 1;
    i = 0;
    str = creat_str_and_count(input_num, &res.len, &len_str);
    res.num = (int *)malloc(sizeof(int) * res.len);
    // printf("\n!!!res -> %s\n%zu\n\n", str, res.len);
    len_str += 3;
    while((len_str -= 4) >= 0)
    {
        temp = ft_atoi_lan(str, len_str);
        res.num[i++] = temp;
    }
    print_lan(res);
    return (res);
}

