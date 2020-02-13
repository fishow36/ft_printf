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

//
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
//

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

int    print_int(t_lst *temp, long long int nbr, int *w_p);
int     print_long(t_lst *temp, long nbr, int *w_p);
int	print_long_long(t_lst *temp, long long nbr, int *w_p);
int	print_short(t_lst *temp, int nbr, int *w_p);
int	print_sshort(t_lst *temp, int nbr, int *w_p);

int    print_uint(t_lst *temp, unsigned long long int nbr, int *w_p);
int	print_ulong(t_lst *temp, unsigned long nbr, int *w_p);
int	print_ulong_long(t_lst *temp, unsigned long long nbr, int *w_p);
int	print_ushort(t_lst *temp, unsigned int nbr, int *w_p);
int	print_usshort(t_lst *temp, int nbr, int *w_p);

int    print_float(t_lst *temp, double input, int *w_p);
int    print_lfloat(t_lst *temp, long double input, int *w_p);

int    print_other(t_lst *temp, int *w_p);
//
void print_node(t_lst *node);
//

t_lst   *create_list(const char *format, int *pos, int amount);

char    *align_width(char *str, int size, t_lst *node);
char    *shorten_str(char *str, int precision);
char    *int_width(char *str, int size, t_lst *node);
char    *add_plus(char *str, char to_add);
char	*add_zero(char *str, char type, int i);

char	*ft_itoa_long(long long n);
char	*ft_itoa_base(unsigned long long value, unsigned long long base);
#endif