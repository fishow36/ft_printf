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

int     ft_printf(const char *format, ...);

t_lst   *new(int pos);
int		lst_push_front(t_lst **head, t_lst *new);
void	lst_reverse(t_lst **head);
void	lst_del(t_lst **head);

int     is_even(const char *format, int i);
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