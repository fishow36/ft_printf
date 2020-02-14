#include "ft_printf.h"

#include<float.h>

int main()
{
    long double test1 = 12800000000000.1230000001234;
    printf("std\t%.50Lf\n", test1);
    ft_printf("our\t%.50Lf\n", test1);

    // t_lanch res;
    // create_lanch(&res);
    // res.num[1] = 1;
    // print_lanch(res);
    // change_lanch_rank(&res, 1);
    // print_lanch(res);
    // print_lanch(power_of_five_lanch(2));    
    
    
    // char *str = "10000000000000000000000000000000000000000000000000000000000000000";
    //double test = 1.25;
    // printf("std %f\n", test);
    // ft_printf("our %f\n", test);
    // printf("\nstd %Lf\n", test1);
    // print_lan(c/reate_lan_from_bitstr(str));
//    t_ulli  for_lan1 = 150000;
    // t_ulli  for_lan2 = 4;
    //t_lan f = create_lan(for_lan1);
    //t_lan s = create_lan(for_lan2);
    //print_lan(f);
    //print_lan(s);
    // ft_putchar('\n');
// print_lan(sub_lan_nums(f, s, 0));
// print_lan(sum_lan_nums(f, s));
// print_lan(mult_lan_nums(f, s));
    // print_lan(div_lan_nums(f, 4));
    // for (int i = 0; i <= 30; i++)
        // print_lanch(power_of_five_lanch(5, 15));
    return (0);
}