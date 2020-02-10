#include <unistd.h>
#include <stdio.h>

typedef unsigned long long int t_ulli;

typedef struct s_dbl
{
    t_ulli          mant : 52;
    unsigned int    exp : 11;
    unsigned int    sign : 1;
} t_dbl;

typedef union u_dbl
{
    double  d;
    t_dbl   parts;
} dbl;

void print_bit(t_ulli num, int shift)
{
    int i = --shift;
    int counter; 
    
    counter = 0;
    while (i > -1)
    {
        if (i > 31)
        {
            if (num & (1 << 31) << (i - 31))
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

void    print_udbl(t_dbl flp)
{
    printf("\nmanti\n");
    print_bit(flp.mant, 52);
    printf("\nsign\texpo\n");
    print_bit(flp.sign, 1);
    printf("    ");
    print_bit(flp.exp, 11);
    printf("\n\n");
}

int main(void) 
{
//   dbl d1;
//   d1.d = 4.5;
//   printf("sign = %u\n", d1.parts.sign);
//   printf("exponent = %u\n", d1.parts.exp);
//   printf("mantisa = %llu\n", d1.parts.mant);
//   print_udbl(d1.parts);
printf("%f", 0.3);
  return (0);
}