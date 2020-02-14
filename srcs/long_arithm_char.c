/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   long_arithm_char.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrogg <mbrogg@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 11:46:34 by mbrogg            #+#    #+#             */
/*   Updated: 2020/02/14 16:45:04 by mbrogg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// lan - long arith num char

/*
**  WIDTH == -1 -> len = 3
**  WIDTH != -1 -> len = WIDTH
*/
int     create_lanch(t_lanch *res, int width)
{
    int c;

    c = 0;
    res->len =  (width == -1) ? 3 : width;
    res->num = (char *)malloc(sizeof(char) * (res->len + 1));
    if (res->num == NULL)
        return (-1);
    while (c < res->len)
        res->num[c++] = 0;
    res->num[c] = '\0';
    printf("CREAT");
    print_lanch(*res);
    printf("\t len %d\n", res->len);
    return (1);
}

void    print_lanch(t_lanch to_print)
{
    int c;

    c = 0;
    while (c < to_print.len)
        printf("%c ", (to_print.num[c++] + '0'));
    printf("\n");
}

int     cpy_lanch_str(t_lanch *dst, t_lanch *src)
{
	size_t	count;

	count = 0;    
	if ((dst->num = (char *)malloc(sizeof(char) * (dst->len + 1))) == NULL)
		return (-1);
	while (count < src->len)
	{
		dst->num[count] = src->num[count];
        count++;
	}
	while (count < dst->len)
		dst->num[count++] = 0;
	dst->num[count] = '\0';
	return (1);
}

/*
**  type == -1 -> rank += 1 
*/
int     change_lanch_rank(t_lanch *p_lan, int type)
{
    t_lanch temp;
    
    temp.len = p_lan->len;
    if (type == -1)
    {
        if (cpy_lanch_str(&temp, p_lan) == -1)
            return (-1);
        free(p_lan->num);
        p_lan->len += 1;
        if (cpy_lanch_str(p_lan, &temp)== -1)
            return (-1);
        free(temp.num);
    }
    else
    {
        if (cpy_lanch_str(&temp, p_lan) == -1)
            return (-1);
        free(p_lan->num);
        p_lan->len = type;
        if (cpy_lanch_str(p_lan, &temp)== -1)
            return (-1);
        free(temp.num);
    }
}

t_lanch   power_of_five_lanch(int num, int width)
{
    t_lanch temp;
    int     remainder;
    int     c;
    int     cp;

    cp = num;
    remainder = 0;
    create_lanch(&temp, width);
    if (width == -1)
        temp.num[0] = 1;
    else
        temp.num[width - num] = 1;
    printf("BEGIN ->");
    print_lanch(temp);
    printf("\n");
    while (cp-- > 0)
    {
        c = (width == -1) ? 0 : width - num;
        while(c < temp.len || remainder > 0)
        {
            // print_lanch(temp);
            if (c == temp.len)
                change_lanch_rank(&temp, -1);
            temp.num[c] = temp.num[c] * 5;
            temp.num[c] = temp.num[c] + remainder;
            remainder = (temp.num[c] > 9) ? temp.num[c] / 10 : 0;
            if (remainder != 0)
                temp.num[c] %= 10;
            c++;
        }
    }
    return (temp);
}

t_lanch   create_lanch_from_bitstr(char *str)
{
    t_lanch res;
    t_lanch temp;
    int     c;
    int     len_str;
    int     length;    

    len_str = ft_strlen(str); 
    create_lanch(&res, -1);
    c = len_str - 1;
    while (c > 0 && str[c] == '0') 
        c--;
    res = power_of_five_lanch(c + 1, -1);
    change_lanch_rank(&res, c + 1);
    // print_lanch(res);
    // printf("%d\n", res.len);
    len_str = c;
    length = res.len;
    c = 0;
    while (c < len_str)
    {
        if (str[c] == '1')
        {
            temp = power_of_five_lanch(c + 1, length);
            print_lanch(temp);
            res = sum_lanch_nums(res, temp);
        }
        c++;
    }
    return (res);
}

/*
**  f - first, s - second
*/

t_lanch   sum_lanch_nums(t_lanch f, t_lanch s)
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
            change_lanch_rank(&f, 1);
        f.num[c] += remainder + (c < s.len ? s.num[c] : 0);
        remainder = (f.num[c] > 9) ? 1 : 0;
        if (remainder == 1)
            f.num[c] -= 10;
        c++;
    }
    return (f);
}

// void    add_rank_for_frac(t_lan *p_lan, int len_of_lan)
// {
//     int *temp;
//     int old_len;
//     int c;
//     int amount;

//     int check;
    
//     c = -1;
//     old_len = p_lan->len;
//     temp = (int *)malloc(sizeof(int) * (p_lan->len));
//     while (++c < p_lan->len)
//         temp[c] = p_lan->num[c];
//     free(p_lan->num);
//     p_lan->len = len_of_lan / 4 + 1;
//     p_lan->num = (int *)malloc(sizeof(int) * (p_lan->len));
//     c = 0;
//     while (c < p_lan->len)
//     {
//         check = (c + 1) * 4;
//         if (check < len_of_lan || c < old_len)
//             p_lan->num[c] = (c < old_len) ? temp[c] : 0;
//         else
//             p_lan->num[c] = dec_power_for_frac(p_lan, len_of_lan, c);
//         c++;
//     }
// }



// /*
// **  IF TYPE == 1 -> f--
// **  WITHOUT NEG_RESULT
// */
// t_lan   sub_lan_nums(t_lan f, t_lan s, int type)
// {
//     int     remainder;
//     size_t  c;
//     size_t  max;
//     t_lan   res;
    
//     if (type == 1)
//     {
//         f.num[f.len - 1] -= 1; 
//     }
//     else
//     {
//         remainder = 0;
//         c = 0;
//         max = f.len > s.len ? f.len : s.len;
//         while(c < max || remainder > 0)
//         {
//             f.num[c] -= remainder + (c < s.len ? s.num[c] : 0);
//             remainder = (f.num[c] < 0) ? 1 : 0;
//             if (remainder == 1 && c + 1 != f.len)
//                 f.num[c] += 10000;
//             c++;
//         }
//     }
//     if (c == f.len)
//         change_lan_rank(&f, 0);
//     return (f);        
// }


// t_lan   mult_lans(t_lan f, t_lan s)
// {
//     t_lan   temp;
//     t_lan   on_sub;
//     int     c;

//     c = -1;
//     on_sub.len = s.len;
//     on_sub.num = (int *)malloc(sizeof(int) * (s.len));
//     while (++c < s.len)
//         on_sub.num[c] = s.num[c];
//     c = -1;
//     temp.len = f.len;
//     temp.num = (int *)malloc(sizeof(int) * (f.len));
//     while (++c < f.len)
//         temp.num[c] = f.num[c];
//     while (on_sub.num[on_sub.len - 1] - 1 > 0)
//     {
//         f = sum_lan_nums(f, temp);
//         on_sub = sub_lan_nums(on_sub, f, 1);
//     }
//     return (f);
// }

// // lnum c (a.size()+b.size());
// // for (size_t i=0; i<a.size(); ++i)
// // 	for (int j=0, carry=0; j<(int)b.size() || carry; ++j) {
// // 		long long cur = c[i+j] + a[i] * 1ll * (j < (int)b.size() ? b[j] : 0) + carry;
// // 		c[i+j] = int (cur % base);
// // 		carry = int (cur / base);
// // 	}
// // while (c.size() > 1 && c.back() == 0)
// // 	c.pop_back();

// t_lan   div_lan_nums(t_lan f, int num)
// {
//     int     remainder;
//     int     c;
//     long long   cur;

//     remainder = 0;
//     c = f.len - 1;
//     while(c >= 0)
//     {
//         // print_lan(f);
//         cur = f.num[c] + remainder * 1ll * 10000;
//         f.num[c] = (int)(f.num[c] / num);
//         remainder = (int)(cur % num);
//         c--;
//     }
//     return (f);
// }

// // int carry = 0;
// // for (int i=(int)a.size()-1; i>=0; --i) {
// // 	long long cur = a[i] + carry * 1ll * base;
// // 	a[i] = int (cur / b);
// // 	carry = int (cur % b);
// // }
// // while (a.size() > 1 && a.back() == 0)
// // 	a.pop_back();
