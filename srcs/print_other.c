#include "ft_printf.h"

int    print_other(t_lst *temp, int *w_p)
{
    return (print_char(temp, temp->type, w_p));
}