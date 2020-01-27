#include "ft_printf.h"

int is_even(const char *format, int i)
{
    int amount;

    amount = 0;
    i--;
    while (format[i] && format[i] == '%')
    {
        if (format[i] == '%')
            amount++;
        i--;
    }
    if (amount % 2 == 0)
        return (1);
    else
        return (0);    
}

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

void print_elem2(t_lst *temp, va_list ap)
{
    if (temp->type == 'c')
        print_char(temp, va_arg(ap, char));
    else if (temp->type == 's')
        print_str(temp, va_arg(ap, char*));
    else if (temp->type == 'p')
        print_ptr(temp, va_arg(ap, void*));
    else if (temp->type == 'f')
    {
        if (temp->length[0] == 'L')
            print_lfloat(temp, va_arg(ap, long double));
        else
            print_float(temp, va_arg(ap, double));      
    }
    else
        print_other(temp);
}

void print_elem(t_lst *temp, va_list ap)
{
    if (temp->type == 'd' || temp->type == 'i')
    {
        if (temp->flags[0] == 'l' && temp->flags[1] != 'l')
            print_long(temp, va_arg(ap, long));
        else if (temp->flags[0] == 'l' && temp->flags[1] == 'l')
            print_long_long(temp, va_arg(ap, long long));
        else if (temp->flags[0] == 'h' && temp->flags[1] != 'h')
            print_short(temp, va_arg(ap, short));
        else if (temp->flags[0] == 'h' && temp->flags[1] == 'h')
            print_char_as_int(temp, va_arg(ap, char));
        else
            print_int(temp, va_arg(ap, int)); 
    }
        
    else if (temp->type == 'o' || temp->type == 'u'
    || temp->type == 'x' || temp->type == 'X')
    {
        if (temp->flags[0] == 'l' && temp->flags[1] != 'l')
            print_ulong(temp, va_arg(ap, unsigned long));
        else if (temp->flags[0] == 'l' && temp->flags[1] == 'l')
            print_ulong_long(temp, va_arg(ap, unsigned long long));
        else if (temp->flags[0] == 'h' && temp->flags[1] != 'h')
            print_ushort(temp, va_arg(ap, unsigned short));
        else if (temp->flags[0] == 'h' && temp->flags[1] == 'h')
            print_char_as_int(temp, va_arg(ap, char));
        else
            print_uint(temp, va_arg(ap, unsigned int)); 
    }
    else
        print_elem2(temp, ap);
}

void    print_from_list(const char *format, t_lst *head, va_list ap)
{
    t_lst *temp;
    int i;

    temp = head;
    i = 0;
    
    while (temp)
    {
        while (i < temp->pos)
        {
            ft_putchar(format[i]);
            i++;
        }
//        print_elem(temp, ap);
        i = temp->next_pos;
        temp = temp->next;
    }
    while (format[i])
    {
            ft_putchar(format[i]);
            i++;
    }
}

int    ft_printf(const char *format, ...)
{
    va_list ap;
    int *pos;
    int amount;
    t_lst *head;
    t_lst *temp;

    amount = 0;
    va_start(ap, format);
    pos = count_args(format, &amount);
    if (amount != 0)
    {
        head = create_list(format, pos, amount);
        temp = head;
        while (head)
        {
            print_node(head);
            head = head->next;
        }
        print_from_list(format, temp, ap);
    }
    else
    {
        ft_putstr(format);
    } 
    va_end(ap); 
    return(0);
}