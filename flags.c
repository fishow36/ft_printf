#include "ft_printf.h"

char    *add_plus(char *str, char to_add)
{
    int len;
    int i;
    char *res;

    len = ft_strlen(str);
    if (!(res = (char*)malloc(sizeof(char) * (len + 2))))
        return (NULL);
    res[len + 1] = '\0';
    res[0] = to_add;
    i = 1;
    while (str[i - 1])
    {
        res[i] = str[i - 1];
        i++;
    }
    ft_strdel(&str);
    return (res);
}