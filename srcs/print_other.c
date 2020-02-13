#include "ft_printf.h"

int    print_other(t_lst *temp, int *w_p)
{
    if (temp->type == 0)
        return (0);
    else
        return (print_char(temp, temp->type, w_p));
}