#include <io.h>
#include <cstdint>
#include <stdio.h>

typedef unsigned long long t_ull;

//  double == 64 bit
//  sign -> expo -> manti
typedef struct  s_udbl
{
    unsigned    sign : 1;
    unsigned    expo : 15;
    t_ull       mant : 64;
}               t_udbl;

typedef union  u_dbl
{
    long double     val;
    t_udbl          under;  
}               t_dbl;

void print_bit(t_ull num, int shift)
{
    int i = --shift;
    int counter; 
    
    counter = 0;
    while (i > -1)
    {
        if (i > 62)
        {
            if (num & (1 << 31) << 31 << i - 62)
                printf("1");
            else
                printf("0");
        }
        else if (i > 31)
        {
            if (num & (1 << 31) << i - 31)
                printf("1");
            else
                printf("0");
        }
        else
        {
            if (num & (1 << i))
                printf("1");
            else
                printf("0");            
        }
        i--;
    }
    printf(" ");
}

int     put_bit(int num, int pos)
{
    num |= 1 << pos;
    return (num);
}

int     del_bit(int num, int pos)
{
    return (num & ~(1 << pos));
}

int     rev_bit(int num, int pos)
{
    return (num ^ (1 << pos));
}

int ft_pow(int n)
{
    int res;

    res = 1;
    while (n--)
        res *= 10;
    return (res);
}

void    print_udbl(t_udbl flp)
{
    printf("\nmanti\n");
    print_bit(flp.mant, 64);
    printf("\nsign\texpo\n");
    print_bit(flp.sign, 1);
    printf("    ");
    print_bit(flp.expo, 11);
    printf("\n\n");
}

void    dtob(double num, int prec)
{
    t_udbl       res;
    t_dbl           un;
    int         i;

    un.val = num;
    // un.under.expo = 0;
    // un.under.sign = 0;
    // un.under.mant = 0;
    print_udbl(un.under);

    // i = 52 - 1;
    // if (num < 0)
    //     res.sign = 1;
    // ull  inum = (ull)num;
    // printf("%d\n", inum);
    // ull  fnum = (ull)((num - (double)inum) * ft_pow(prec));
    // printf("%d\n", fnum);
    
    // while (inum > 0)
    // {
    //     if (inum % 2 == 1)
    //         res.mant  = put_bit(res.mant, i);
    //     --i;
    //     printf("`%d\n", inum % 2);
    //     print_udbl(res);
    //     inum /= 2;
    // }

    // res.mant = 31;
    // printf("%ull", res.mant);
    // i = 1;
    // int j = 0;
    // while (i < 52)
    // {
    //     if (!(res.mant & (1 << i++))) 
    //         j++;
    //     else
    //         break;
    // } 
    // printf("~~%d\n", j);
    // // res.mant |= (ull)(1 << 3);
    // print_bit(res.mant, 64);
    // print_udbl(res);
}

int main()
{
    long double test1 = 16;
    dtob(test1, 3);
    return (0);
}
