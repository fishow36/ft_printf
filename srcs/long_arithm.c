/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   long_arithm.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrogg <mbrogg@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 11:46:34 by mbrogg            #+#    #+#             */
/*   Updated: 2020/02/14 10:48:51 by mbrogg           ###   ########.fr       */
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

    c = 0;
    len_str = ft_strlen(str); 
    res.num = (int *)malloc(sizeof(int) * 1);
    res.num[0] = 0;
    res.len = 1;
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
    else
    {
        // LOGARIFM!! 2 ^ (-N) = 10 ^ (-N) * 5 ^ N
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

t_lan   power_two_lan(int num)
{
    t_lan   res;
    t_lan   on_mult;

    res.num = (int *)malloc(sizeof(int) * 1);
    on_mult = create_lan(2);
    if (num < 0)
    {
        while(num++ < 0)
        {
            print_lan(res);
            res = div_lan_nums(res, 2);
        }
    }
    else
        while(num-- > 0)
        {
            // printf("±±±");
            // print_lan(res);
            // printf("\n");
            // res = mult_lan_nums(res, on_mult);
        }
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

/*
**  IF TYPE == 1 -> f--
**  WITHOUT NEG_RESULT
*/
t_lan   sub_lan_nums(t_lan f, t_lan s, int type)
{
    int     remainder;
    size_t  c;
    size_t  max;
    t_lan   res;
    
    if (type == 1)
    {
        f.num[f.len - 1] -= 1; 
    }
    else
    {
        remainder = 0;
        c = 0;
        max = f.len > s.len ? f.len : s.len;
        while(c < max || remainder > 0)
        {
            f.num[c] -= remainder + (c < s.len ? s.num[c] : 0);
            remainder = (f.num[c] < 0) ? 1 : 0;
            if (remainder == 1 && c + 1 != f.len)
                f.num[c] += 10000;
            c++;
        }
    }
    if (c == f.len)
        change_lan_rank(&f, 0);
    return (f);        
}


t_lan   mult_lans(t_lan f, t_lan s)
{
    t_lan   temp;
    t_lan   on_sub;
    int     c;

    c = -1;
    on_sub.len = s.len;
    on_sub.num = (int *)malloc(sizeof(int) * (s.len));
    while (++c < s.len)
        on_sub.num[c] = s.num[c];
    c = -1;
    temp.len = f.len;
    temp.num = (int *)malloc(sizeof(int) * (f.len));
    while (++c < f.len)
        temp.num[c] = f.num[c];
    while (on_sub.num[on_sub.len - 1] - 1 > 0)
    {
        f = sum_lan_nums(f, temp);
        on_sub = sub_lan_nums(on_sub, f, 1);
    }
    return (f);
}

// lnum c (a.size()+b.size());
// for (size_t i=0; i<a.size(); ++i)
// 	for (int j=0, carry=0; j<(int)b.size() || carry; ++j) {
// 		long long cur = c[i+j] + a[i] * 1ll * (j < (int)b.size() ? b[j] : 0) + carry;
// 		c[i+j] = int (cur % base);
// 		carry = int (cur / base);
// 	}
// while (c.size() > 1 && c.back() == 0)
// 	c.pop_back();

t_lan   div_lan_nums(t_lan f, int num)
{
    int     remainder;
    int     c;
    long long   cur;

    remainder = 0;
    c = f.len - 1;
    while(c >= 0)
    {
        print_lan(f);
        cur = f.num[c] + remainder * 1ll * 10000;
        f.num[c] = (int)(f.num[c] / num);
        remainder = (int)(cur % num);
        c--;
    }
    return (f);
}

// int carry = 0;
// for (int i=(int)a.size()-1; i>=0; --i) {
// 	long long cur = a[i] + carry * 1ll * base;
// 	a[i] = int (cur / b);
// 	carry = int (cur % b);
// }
// while (a.size() > 1 && a.back() == 0)
// 	a.pop_back();
