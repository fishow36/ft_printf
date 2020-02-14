/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   long_arithm.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrogg <mbrogg@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 11:46:34 by mbrogg            #+#    #+#             */
/*   Updated: 2020/02/14 23:14:20 by mbrogg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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


t_lan   power_of_five_lan(int num)
{
    t_lan   temp;
    int     remainder;
    int     c;
    
    remainder = 0;
    temp.len = 1;
    temp.num = (int *)malloc(sizeof(int) * (temp.len));
    temp.num[0] = 1;
    while (num-- > 0)
    {
        c = 0;
        while(c < temp.len || remainder > 0)
        {
            if (c == temp.len)
                change_lan_rank(&temp, 1);
            temp.num[c] *= 5;
            temp.num[c] += remainder;
            remainder = (temp.num[c] > 9999) ? temp.num[c] / 10000: 0;
            if (remainder != 0)
                temp.num[c] %= 10000;
            c++;
        }
    }
    // print_lan(temp);
    return (temp);
}

static int     power_dec(int power)
{
    if (power == 0)
        return (0);
    else if (power == 1)
        return (1);
    else if (power == 2)
        return (10);
    else if (power == 3)
        return (100);
    else
        return (1000);
}

static  int dec_power_for_frac(t_lan *p_lan, int number, int c)
{
    int power;

    if (p_lan->num[c] != 0)
        return (p_lan->num[c] + power_dec(number + 1 - c * 4));
    else
        return (power_dec(number + 1 - c * 4));
}

void    add_rank_for_frac(t_lan *p_lan, int len_of_lan)
{
    int *temp;
    int old_len;
    int c;
    int amount;

    int check;
    
    c = -1;
    old_len = p_lan->len;
    temp = (int *)malloc(sizeof(int) * (p_lan->len));
    while (++c < p_lan->len)
        temp[c] = p_lan->num[c];
    free(p_lan->num);
    p_lan->len = len_of_lan / 4 + 1;
    p_lan->num = (int *)malloc(sizeof(int) * (p_lan->len));
    c = 0;
    while (c < p_lan->len)
    {
        check = (c + 1) * 4;
        if (check < len_of_lan || c < old_len)
            p_lan->num[c] = (c < old_len) ? temp[c] : 0;
        else
            p_lan->num[c] = dec_power_for_frac(p_lan, len_of_lan, c);
        c++;
    }
}

/*
** TYPE == 1 -> INTEGER PART OF NUMBER
** TYPE == 2 -> FRACT PART OF NUMBER
*/

t_lan   create_lan_from_bitstr(char *str, int type)
{
    t_lan   res;
    t_lan   temp;
    int     c;
    int     len_str;

    len_str = ft_strlen(str); 
    res.num = (int *)malloc(sizeof(int) * 1);
    res.num[0] = 0;
    res.len = 1;
    c = 0;
    if (type == 1)
    {
        while (len_str - c > 0)
        {
            if (str[len_str - c - 1] == '1')
            {
                temp = power_of_two_lan(c);
                res = sum_lan_nums(res, temp);
            }
            c++;
        }
    }
    return (res);
}

t_lan   power_of_two_lan(int num)
{
    t_lan   temp;
    int     c;

    c = -1;
    temp.len = 1;
    temp.num = (int *)malloc(sizeof(int) * (temp.len));
    temp.num[0] = 1;
    while (num-- > 0)
        temp = sum_lan_nums(temp, temp);
    return (temp);
}

/*
**  type == 1 -> rank++
**  type == 0 -> ranl-- (until there is no free items)
*/
void    change_lan_rank(t_lan *p_lan, int type)
{
    int *temp;
    int c;
    int amount;
    
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
    else
    {
        c = p_lan->len;
        amount = 0;
        while (p_lan->num[--c] == 0 && c > 0)
            amount++;
        c = -1;
        temp = (int *)malloc(sizeof(int) * (p_lan->len));
        while (++c < p_lan->len)
            temp[c] = p_lan->num[c];
        free(p_lan->num);
        p_lan->len -= amount;
        p_lan->num = (int *)malloc(sizeof(int) * (p_lan->len));
        c = -1;
        while (++c < p_lan->len)
            p_lan->num[c] = temp[c];
    }
}

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
