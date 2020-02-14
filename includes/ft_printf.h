#ifndef FT_PRINTF_H
# define FT_PRINTF_H

//
#include <stdio.h>
//
#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>
#include "libft.h"

typedef	struct	s_lst
{
	int     pos;
    int     index;
    char    flags[5];
    char    *width;
    char    *precision;
    char    length[2];
    char    type;
    int     next_pos;       
    struct s_lst  *next;
}				t_lst;

typedef unsigned long long int t_ulli;

typedef struct      s_dbl_struct
{
    t_ulli          mant : 52;
    unsigned int    exp : 11;
    unsigned int    sign : 1;
}                   t_dbl_struct;

typedef union       u_dbl
{
    double          origin;
    t_dbl_struct    parts;
}                   t_dbl;

typedef struct      s_ldbl_struct
{
    t_ulli          mant : 64;
    unsigned int    exp : 15;
    unsigned int    sign : 1;
}                   t_ldbl_struct;

typedef union       u_ldbl
{
    long double     origin;
    t_ldbl_struct   parts;
}                   t_ldbl;

typedef struct      u_lan
{
    int             *num;
    size_t          len;
}                   t_lan;

typedef struct      u_lanch
{
    char            *num;
    size_t          len;
}                   t_lanch;

int     ft_printf(const char *format, ...);

t_lst   *new(int pos);
int		lst_push_front(t_lst **head, t_lst *new);
void	lst_reverse(t_lst **head);
void	lst_del(t_lst **head);

int     type_pos(const char *format, int pos);
void    change_case(char **str);
int     *count_args(const char *format, int *amount);
int     find_flags(const char *format, int pos, t_lst **node);
int     find_width(const char *format, int pos, t_lst **node);
int     find_prec(const char *format, int pos, t_lst **node);
int     find_length(const char *format, int pos, t_lst **node);
int     find_type(const char *format, int pos, t_lst **node);

void    print_char(t_lst *temp, int c, int *w_p);
void    print_str(t_lst *temp, char *str, int *w_p);
void    print_ptr(t_lst *temp, void *ptr, int *w_p);

void    print_int(t_lst *temp, long long int nbr, int *w_p);
void	print_long(t_lst *temp, long nbr, int *w_p);
void	print_long_long(t_lst *temp, long long nbr, int *w_p);
void	print_short(t_lst *temp, int nbr, int *w_p);

void    print_uint(t_lst *temp, unsigned long long int nbr, int *w_p);
void	print_ulong(t_lst *temp, unsigned long nbr, int *w_p);
void	print_ulong_long(t_lst *temp, unsigned long long nbr, int *w_p);
void	print_ushort(t_lst *temp, unsigned int nbr, int *w_p);

void    print_lfloat(t_lst *temp, long double input, int prec);
char	*str_from_db(t_lan i_db, t_lanch f_db, int prec);
char	*ft_dtoa_two(t_ulli value, int shift);

t_lan   create_lan(t_ulli input_num);
char    *creat_str_and_count(t_ulli input_num, size_t *len, int *len_str);
void    print_lan(t_lan to_print);
t_lan   sum_lan_nums(t_lan f, t_lan s);
t_lan   sub_lan_nums(t_lan f, t_lan s, int type);
t_lan   mult_lans(t_lan f, t_lan s);
t_lan   div_lan_nums(t_lan f, int num);
t_lan   power_two_lan(int num);
t_lan   power_of_two_lan(int num);
t_lan   power_of_five_lan(int num);
void    add_rank_for_frac(t_lan *p_lan, int len_of_lan);
t_lan   create_lan_from_bitstr(char *str, int type);
void    change_lan_rank(t_lan *p_lan, int type);

int     create_lanch(t_lanch *res, int width);
void    print_lanch(t_lanch to_print);
int     change_lanch_rank(t_lanch *p_lan, int type);
int     cpy_lanch_str(t_lanch *dst, t_lanch *src);
t_lanch power_of_five_lanch(int num, int width);
t_lanch create_lanch_from_bitstr(char *str);
t_lanch sum_lanch_nums(t_lanch f, t_lanch s);
void    print_other(t_lst *temp, int *w_p);
//
void print_node(t_lst *node);
//

t_lst   *create_list(const char *format, int *pos, int amount);

char    *align_width(char *str, int size, t_lst *node);
char    *shorten_str(char *str, int precision);
char    *int_width(char *str, int size, t_lst *node);
char    *add_plus(char *str, char to_add);
char    *add_zero(char *str, char type, int prec);

char	*ft_itoa_long(long long n);
char	*ft_itoa_base(unsigned long long value, unsigned long long base);
#endif