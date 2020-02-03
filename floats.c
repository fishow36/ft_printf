#include <io.h>
#include <stdio.h>

//  double == 64 bit
//  sign -> expo -> manti
typedef struct  s_dbl_p
{
    unsigned                sign : 1;
    unsigned                expo : 11;
    unsigned long long      mant : 52;
}               t_dbl_p;

void print_bit(unsigned num, int shift)
{
    for (int i = --shift; i > -1 ; i--)
    {
        if (num & (1 << i))
            printf("1");
        else
            printf("0");
    }
    printf(" ");
}

int     put_bit(int num, int pos)
{
    return (num | 1 << pos);
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

void    print_dbl_p(t_dbl_p flp)
{
    printf("manti\n");
    print_bit(flp.mant, 52);
    printf("\nsign\texpo\n");
    print_bit(flp.sign, 1);
    printf("    ");
    print_bit(flp.expo, 11);
    printf("\n\n");
}

void    ftob(double num, int prec)
{
    t_dbl_p       res;
    res.expo = 0;
    res.mant = 0;
    res.sign = 0;
    int         i;
    if (num < 0)
        res.sign |= 1;
    unsigned long long  inum = (unsigned)num;
    printf("%d\n", inum);
    unsigned long long  fnum = (unsigned)(num - (double)inum) * ft_pow(prec);
    printf("%d\n", fnum);
    res.mant = inum;
    // while (inum)
    // {
    //     if (inum % 2 == 1)
    //         res.mant |= 1 << i;
    //     inum /= 2;
    //     i++;
    // }
    print_dbl_p(res);
}

int main()
{
    float test1 = 3.0;
    ftob(test1, 3);
    return (0);
}