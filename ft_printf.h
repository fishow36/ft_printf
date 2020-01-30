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

t_lst *new(int pos);
int		lst_push_front(t_lst **head, t_lst *new);
void	lst_reverse(t_lst **head);
void	lst_del(t_lst **head);

int     is_even(const char *format, int i);
int     *count_args(const char *format, int *amount);
int     find_flags(const char *format, int pos, t_lst **node);
int     find_width(const char *format, int pos, t_lst **node);
int     find_prec(const char *format, int pos, t_lst **node);
int     find_length(const char *format, int pos, t_lst **node);
int     find_type(const char *format, int pos, t_lst **node);

void    print_char(t_lst *temp, int c, va_list ap, int *w_p);
void    print_str(t_lst *temp, char *str, va_list ap, int *w_p);
//
void print_node(t_lst *node);
//

char *align_width(char *str, int size, t_lst *node);
char *shorten_str(char *str, int precision);
#endif