/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   long_arithm.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrogg <mbrogg@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 11:46:34 by mbrogg            #+#    #+#             */
/*   Updated: 2020/02/13 17:27:44 by mbrogg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// lan - long arith num

void    print_lan(t_lan to_print)
{
    int counter;

    counter = 0;
    while (counter < to_print.len)
        printf("%d\t", to_print.num[counter++]);
    printf("\n");
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

char    *creat_str_for_count(t_ulli input_num, size_t len, int len_str)
{
    char    *res;
    t_ulli  cpy;
    int     counter;

    res = (char *)malloc(sizeof(char) * (len_str + 1));
    counter = len_str - 1;
    while (counter >= 0)
    {
        res[counter--] = input_num % 10 + '0';
        input_num /= 10;
    }
    res[len_str] = '\0';
    return (res);
}

size_t  count_for_lan(t_ulli input_num, size_t *len)
{
    size_t  len_str;

    len_str = 0;
    *len = 0;
    while(input_num > 0)
    {
        len_str++;
        input_num /= 10;
    }
    *len = len_str / 4;
    *len += (len_str % 4 == 0) ? 0 : 1;
    return (len_str);
}

// t_lan   fill_lan(size_t size)
// {
//     t_lan   res;

//     res.num = (int *)malloc(sizeof(int) * size);
//     return (res); 
// }

t_lan   create_lan(t_ulli input_num)
{
    t_lan   res;
    int     i;
    int     count;
    char    *str;
    int     len_str;

    count = 1;
    i = 0;
    
    len_str = count_for_lan(input_num, &res.len); 
    res.num = (int *)malloc(sizeof(int) * res.len);
    str = creat_str_for_count(input_num, res.len, len_str);
    // printf("\n!!!res -> %s\n%zu\n\n", str, res.len);
    len_str += 3;
    while((len_str -= 4) >= 0)
        res.num[i++] = ft_atoi_lan(str, len_str);
    // print_lan(res);
    return (res);
}

/*
**  type == 1 -> rank++
**  type == 0 -> ranl-- (until there is no free items)
*/
void    change_lan_rank(t_lan *p_lan, int type)
{
    int *temp;
    int c;
    
    c = -1;
    if (type == 1)
    {
        temp = (int *)malloc(sizeof(int) * (p_lan->len));
        while (++c < p_lan->len)
            temp[c] = p_lan->num[c];
        free(p_lan->num);
        p_lan->len++;
        p_lan->num = (int *)malloc(sizeof(int) * (p_lan->len));
        c = -1;
        while (++c < p_lan->len - 1)
            p_lan->num[c] = temp[c];
        p_lan->num[c] = 0;
    }
}

/*
**  f - first, s - second
*/

t_lan   sum_lan_nums(t_lan f, t_lan s)
{
    int     remainder;
    size_t  c;
    size_t  max;
    
    remainder = 0;
    c = 0;
    max = f.len > s.len ? f.len : s.len;
    while(c < max || remainder > 0)
    {
        if (c == f.len)
            change_lan_rank(&f, 1);
        f.num[c] += remainder + (c < s.len ? s.num[c] : 0);
        remainder = (f.num[c] > 9999) ? 1 : 0;
        if (remainder == 1)
            f.num[c] -= 10000;
        c++;
    }
    return (f);
}