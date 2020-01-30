#include "ft_printf.h"

char *align_width(char *str, int size, t_lst *node)
{
    char *res;
    int i;
    int j;
    char filler;
    char side;

    if (!(res = (char*)malloc(sizeof(char) * (size + 1))))
        return (NULL);
    filler = ' ';
    side = 'r';
    i = 0;
    if(node->flags[0] == '0')    filler = ' ';
        filler = '0';
    if (node->flags[2] == '-')
        side = 'l';
    if (side == 'l')
    {
        {
            res[i] = str[i];
            i++;
        }
        while (i < size)
        {
            res[i] = filler;
            i++;
        }
    }
    else
    {
        while (i < size - ft_strlen(str))
        {
            res[i] = filler;
            i++;
        }
        j = 0;
        while (i < size)
        {
            res[i] = str[j];
            i++;
            j++;
        }
    }
    res[i] = '\0';
    return (res);
}

char *shorten_str(char *str, int precision)
{
    char *res;
    int i;

    i = 0;
    if (!(res = (char*)malloc(sizeof(precision + 1))))
        return (NULL);
    res[precision] = '\0';
    while (i < precision)
    {
        res[i] = str[i];
        i++;
    }
    return (res);
}