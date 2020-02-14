//#include "ft_printf.h"
//#include <limits.h>

#include "ft_printf.h"

int main(void)
{
    char c;
    int i;
    char *str;

    i = 12;
   
    ft_printf("% -015f %d %d %100d\n", 10.205, 2, 3, 4);

    printf("\n");
    printf("% -015f %d %d %100d\n", 10.205, 2, 3, 4);

    return (0);
}