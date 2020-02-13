#include "ft_printf.h"


int main()
{
    double test = 1.25;
    long double test1 = 100.332423;
    // printf("std %f\n", test);
    // ft_printf("our %f\n", test);
    // printf("\nstd %Lf\n", test1);
    // ft_printf("our %Lf\n", test1);

    t_ulli  for_lan1 = 123456789;
    t_ulli  for_lan2 = 987654321;
    t_lan f = create_lan(for_lan1);
    t_lan s = create_lan(for_lan2);
    print_lan(f);
    print_lan(s);
    print_lan(sum_lan_nums(f, s));
    return (0);
}