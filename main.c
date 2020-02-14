//#include "ft_printf.h"
//#include <limits.h>

#include "ft_printf.h"

int main(void)
{
    char c;
    int i;
    char *str;

    i = 12;
   
    ft_printf("% -015f\n", 10.205);

    printf("\n");
    printf("%0- 15f\n", 10.205);

    return (0);
}