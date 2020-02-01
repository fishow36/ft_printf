#include "ft_printf.h"

char	*ft_itoa_base(long long value, int base);

int main(void)
{
    char str[5];
//    ft_printf("% +07.10i\n", -1234);
    printf("%X\n", -155);
//    ft_printf("%.2s\n", "serebro");
//    printf("%.2s\n", "serebro");
//    fill_char(5, (char**)(&str));


    printf("%s\n", ft_itoa_base(0, 16));
    return (0);
}