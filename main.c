#include "ft_printf.h"

int main(void)
{
    char str[5];
    ft_printf("% +07d\n", -1234);
    printf("% +07d\n", -1234);
//    ft_printf("%.2s\n", "serebro");
//    printf("%.2s\n", "serebro");
//    fill_char(5, (char**)(&str));
    return (0);
}