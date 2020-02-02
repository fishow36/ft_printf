#include "ft_printf.h"

int *count_args(const char *format, int *amount)
{
    int i;
    int j;
    int *pos;

    i = -1;
    while (format[++i])
        if (format[i] == '%' && format[i + 1] != '%'
        && is_even(format, i) == 1 && format[i + 1] != '\0')
            (*amount)++;
    pos = (int*)malloc(sizeof(int) * (*amount));
    i = -1;
    j = 0;
    while (format[++i])
        if (format[i] == '%' && format[i + 1] != '%'
        && is_even(format, i) == 1 && format[i + 1] != '\0')
            {
                pos[j] = i;
                j++;
            }
    return (pos);
}

int fill_node(const char *format, int pos, t_lst **node)
{
    pos++;
    (*node)->width = NULL;
    (*node)->precision = NULL;
    pos = find_flags(format, pos, node);
    pos = find_width(format, pos, node);
    pos = find_prec(format, pos, node);
    pos = find_length(format, pos, node);
    pos = find_type(format, pos, node);
    (*node)->next_pos = pos;
    return (pos);
}

t_lst *create_list(const char *format, int *pos, int amount)
{
    t_lst *head;
    t_lst *temp;
    int i;
    int j;

    i = 0;
    j = 1;
    
    head = new(pos[0]);
    i = fill_node(format, pos[0], &head);
    while (j < amount)
    {
        temp = new(pos[j]) ;  
        i = fill_node(format, pos[j], &temp);
        if (i == -1)
            return (NULL);
        lst_push_front(&head, temp);
        j++;
    }
    lst_reverse(&head);
    return (head);
}