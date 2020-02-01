#include "ft_printf.h"

char	*ft_itoa_base(unsigned long long value, int base);

int main(void)
{
//    char str[5];
    ft_printf("% -+030d\n", 21447);
    printf("% -0+30d\n", 21447);
//    ft_printf("%.2s\n", "serebro");
//    printf("%.2s\n", "serebro");
//    fill_char(5, (char**)(&str));


    return (0);
}