#include "ft_printf.h"


int main()
{
    double test = 1.25;
    long double test1 = 100.332423;
    // printf("std %f\n", test);
    // ft_printf("our %f\n", test);
    printf("\nstd %Lf\n", test1);
    ft_printf("our %Lf\n", test1);

    // t_ulli  for_lan1 = 10000000;
    // t_ulli  for_lan2 = 1024;
    // t_lan f = create_lan(for_lan1);
    // t_lan s = create_lan(for_lan2);
    // print_lan(f);
    // print_lan(s);
    // ft_putchar('\n');
    // print_lan(sub_lan_nums(f, s, 0));
    // print_lan(sum_lan_nums(f, s));
    // print_lan(mult_lan_nums(f, s));

    // printf("%llu\n", for_lan2);
    // int counter = 0;
    // while (counter++ < 10)
    //     print_lan(neg_power_lan(for_lan2, counter));
    return (0);
}