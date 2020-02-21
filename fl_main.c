#include "ft_printf.h"

#include <float.h>
#include <math.h>

int main()
{
    long double test_max = LDBL_MAX;
    long double test_min = LDBL_MIN;
    double test = 4.375;
    long double test1 = 123456789.777918236412341234;
    long double test2 = 12.7;
    long double test3 = 0.00000000;
    long double test4 = 0.00123456789;

//   ft_printf("our %#.16o\n", -875);
    ft_printf("%.15f\n",        1.025978548534310421);
    long double dubb = NAN;
    printf("%.15f\n",        1.025978548534310421);
    // t_lan *tes;

    //             tes = power_of_two_lan(36);
    //             			printf("!");
	// 		for (int i = 0; i < tes->len; i++)
	// 			printf("%d ", tes->num[i]);
	// 		printf("\n");

    // if ((test1 = (t_lan *)malloc(sizeof(t_lan) * 1)) == NULL)
	// 	exit(1);
    // if ((test1->num = (int *)malloc(sizeof(int) * 1)) == NULL)
	// 	exit(1);
    // test1->len = 1;
    // test1->num[0] = 10;
    // t_lan *test2;
    // if ((test2 = (t_lan *)malloc(sizeof(t_lan))) == NULL)
	// 	exit(1);
    // if ((test2->num = (int *)malloc(sizeof(int) * 1)) == NULL)
	// 	exit(1);
    // test2->len = 1;
    // test2->num[0] = 100;

    // test1 = sum_lan_nums(test1, test2);

    // for (int i = 0; i < test1->len; i++)
	// 		printf("%d ", test1->num[i]);
	// 	printf("\n");

    // ft_printf("%.51Lf\n", test1);
    // ft_printf("%.51Lf\n", test2);
    // ft_printf("%.51Lf\n", test3);
    // ft_printf("%.51Lf\n", test4);
    return (0);
}