#include "ft_printf.h"

void    align_left(char **res, char *str, int size, char filler)
{
    int i;

    i = 0;
    while(str[i])
    {
        (*res)[i] = str[i];
        i++;
    }
    while (i < size)
    {
        (*res)[i] = filler;
        i++;
    }
    (*res)[i] = '\0';
}

void    align_right(char **res, char *str, int size, char filler)
{
    int i;
    int j;

    i = 0;
    while (i < size - (int)ft_strlen(str))
    {
        (*res)[i] = filler;
        i++;
    }
    j = 0;
    while (i < size)
    {
        (*res)[i] = str[j];
        i++;
        j++;
    }
    (*res)[i] = '\0';
}

char    *align_width(char *str, int size, t_lst *node)
{
    char    *res;
    char    filler;

    if (!(res = (char*)malloc(sizeof(char) * (size + 1))))
        return (NULL);
    filler = ' ';
    if (node->flags[0] == '0')
        filler = '0';
    if (node->flags[2] == '-')
        align_left(&res, str, size, filler);
    else
        align_right(&res, str, size, filler);
    ft_strdel(&str);
    return (res);
}