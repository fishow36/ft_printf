#include "ft_printf.h"

void    print_other(t_lst *temp, int *w_p)
{
    print_char(temp, temp->type, w_p);
}