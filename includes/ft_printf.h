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
	int     stars;
	struct s_lst  *next;
}				t_lst;

typedef unsigned long long int t_ulli;

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
char	*fill_number(const char *format, int *pos, int *len, char w_or_p);
char	*find_w_or_p(const char *format, int len, int temp);
int     *count_args(const char *format, int *amount);
int     find_flags(const char *format, int pos, t_lst **node);
int     find_width(const char *format, int pos, t_lst **node);
int     find_prec(const char *format, int pos, t_lst **node);
int     find_length(const char *format, int pos, t_lst **node);
int     find_type(const char *format, int pos, t_lst **node);

int     print_elem(t_lst *temp, va_list ap);
int     print_elem1(t_lst *temp, va_list ap, int *w_p);
int     print_elem2(t_lst *temp, va_list ap, int *w_p);
int     print_elem3(t_lst *temp, va_list ap, int *w_p);

int    print_char(t_lst *temp, int c, int *w_p);
int    print_str(t_lst *temp, char *str, int *w_p);
int    print_ptr(t_lst *temp, void *ptr, int *w_p);

void	add_s_or_p(char **str, t_lst *temp, long long int nbr);
void    zero_flag(char **str, long long int nbr, t_lst *temp, int *w_p);
void	prec_greater(char **str, t_lst **temp, int *w_p);
void    prec_no_width(char **str, t_lst *temp, long long int nbr, int *w_p);
char    *create_str(long long int nbr, int *w_p);
void    add_and_change(char **str, long long int nbr, t_lst **temp);
void	prec_and_width(t_lst **temp, char **str, int *w_p);

int     print_int(t_lst *temp, long long int nbr, int *w_p);
int     print_long(t_lst *temp, long nbr, int *w_p);
int     print_long_long(t_lst *temp, long long nbr, int *w_p);
int     print_short(t_lst *temp, int nbr, int *w_p);
int     print_sshort(t_lst *temp, int nbr, int *w_p);

char    *create_str_u(unsigned long long nbr, t_lst **temp, int *w_p, char *flag);
void    prec_u(char **str, t_lst *temp, int *w_p);
void    width_u(char **str, t_lst *temp, int *w_p);

int     print_uint(t_lst *temp, unsigned long long int nbr, int *w_p);
int     print_ulong(t_lst *temp, unsigned long nbr, int *w_p);
int     print_ulong_long(t_lst *temp, unsigned long long nbr, int *w_p);
int     print_ushort(t_lst *temp, unsigned int nbr, int *w_p);
int     print_usshort(t_lst *temp, int nbr, int *w_p);

char	*lfloat(long double input, int prec);
int     print_float(t_lst *temp, double input, int *w_p);
int		print_lfloat(t_lst *temp, long double input, int *w_p);
char	*str_from_db(t_lan i_db, t_lanch f_db, int prec, int sign);
char	*ft_dtoa_two(t_ulli value, int shift, int *res_len);

char	*lfloat(long double input, int prec);
t_lanch	power_of_five_lanch(int num, int width);
int 	create_lanch_from_bitstr(t_lanch *res, char *str, int prec);
t_lanch	sum_lanch_nums(t_lanch f, t_lanch s);
int		create_lanch(t_lanch *res, int width);
int		precision_in_da_house(t_lanch *res, int prec);
t_lan	create_lan_from_bitstr(char *str);
t_lan	power_of_two_lan(int num);
t_lan	sum_lan_nums(t_lan f, t_lan s);
char	*str_from_db(t_lan i_db, t_lanch f_db, int prec, int sign);
void	ft_strrev(char **str);
int		create_lanch(t_lanch *res, int width);

int     print_other(t_lst *temp, int *w_p);
t_lst   *create_list(const char *format, int *pos, int amount);

char    *align_width(char *str, int size, t_lst *node);
char    *shorten_str(char *str, int precision);
char    *int_width(char *str, int size, t_lst *node);
char    *add_plus(char *str, char to_add);
char	*add_zero(char *str, char type, int i);

char	*ft_itoa_long(long long n);
char	*ft_itoa_base(unsigned long long value, unsigned long long base);
#endif