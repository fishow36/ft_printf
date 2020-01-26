#include "ft_printf.h"

int find_flags(const char *format, int pos, t_lst **node)
{
    int i;

    i = 0;
    while ((format[pos] == '0' || format[pos] == '+'
    || format[pos] == '-' || format[pos] == ' '
    || format[pos] == '#') && format[pos])
    {
        if (format[pos] == '0')
            (*node)->flags[0] = '0';
        else if (format[pos] == '+')
            (*node)->flags[1] = '+';
        else if (format[pos] == '-')
            (*node)->flags[2] = '-';
        else if (format[pos] == ' ')
            (*node)->flags[3] = ' ';
        else if (format[pos] == '#')
            (*node)->flags[4] = '#';
        pos++;
    }
    return (pos);
}

int find_width(const char *format, int pos, t_lst **node)
{
    int len;
    int temp;

    len = 0;
    if (format[pos] == '*')
    {
        pos++;
        if (!((*node)->width = (char*)malloc(sizeof(char) * 1)))
            return (-1);
        (*node)->width[0] = '*';
    }
    else
    {
        temp = pos;
        while (format[pos] >47 && format[pos] < 58)
        {
            pos++;
            len++;
        }
        if (len == 0)
            return (pos);
        else if (!((*node)->width = (char*)malloc(sizeof(char) * (len + 1))))
            return (-1);
        len = 0;
        while (format[temp] >47 && format[temp] < 58)
        {
            (*node)->width[len] = format[temp];
            len++;
            temp++;
        }
        (*node)->width[len] = '\0';
    }
    return (pos);
}

int find_prec(const char *format, int pos, t_lst **node)
{
    int len;
    int temp;

    len = 0;
    temp = pos;
    if (format[pos] == '.')
    {
        pos++;
        if (format[pos] == '*')
        {
            pos++;
            if (!((*node)->precision = (char*)malloc(sizeof(char) * 1)))
                return (-1);
            (*node)->precision[0] = '*';
        }
        else
        {
            temp = pos;
            while (format[pos] >47 && format[pos] < 58)
            {
                pos++;
                len++;
            }
            if (len == 0)
                return (pos);
            else if (!((*node)->precision = (char*)malloc(sizeof(char) * (len + 1))))
                return (-1);
            len = 0;
            while (format[temp] >47 && format[temp] < 58)
            {
                (*node)->precision[len] = format[temp];
                len++;
                temp++;
            }
            (*node)->precision[len] = '\0';
        }
    }
    return (pos);
}

int find_length(const char *format, int pos, t_lst **node)
{
    if (format[pos] == 'L')
    {
        (*node)->length[0] = 'L';
        return (pos + 1);
    }
    else if (format[pos] == 'h')
    {
        (*node)->length[0] = 'h';
        if (format[pos + 1] == 'h')
        {
            (*node)->length[1] = 'h';
            return (pos + 2);
        }
        else
            return (pos + 1);        
    }
    else if (format[pos] == 'l')
    {
        (*node)->length[0] = 'l';
        if (format[pos + 1] == 'l')
        {
            (*node)->length[1] = 'l';
            return (pos + 2);
        }
        else
            return (pos + 1);        
    }
    else
        return (pos);
}

int find_type(const char *format, int pos, t_lst **node)
{
    if (format[pos] == 'c' || format[pos] == 's' || format[pos] == 'p'
    || format[pos] == 'd' || format[pos] == 'i' || format[pos] == 'o'
    || format[pos] == 'u' || format[pos] == 'x' || format[pos] == 'X'
    || format[pos] == 'f')
    {
        (*node)->type = format[pos];
        return (pos + 1);
    }
    else
    {
        (*node)->type = format[pos];
        return (-1);
    }
}