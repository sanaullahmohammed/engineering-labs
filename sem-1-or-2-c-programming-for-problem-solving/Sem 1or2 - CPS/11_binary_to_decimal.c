#include<stdio.h>
#include<stdlib.h>

int decimal = 0;
int bintodec(int num, int x, int base);

void main()
{
    int n, num, r, x=0, z=0, base = 1;
    printf("Enter a binary number\n");
    printf("****************\n");
    scanf("%d",&n);
    num = n;

    while(n > 0)
    {
        r = n%10;
        if(r > 1)
            z = 1;
        x++;
        n = n/10;
    }
    if(z == 1)
        printf("Invalid Binary Number\n");
    else
    {
        bintodec(num, x, base);
        printf("Binary number = %d\n", num);
        printf("Decimal Number = %d\n", decimal);
    }
}

int bintodec(int num, int x, int base)
{
    if(x == 0)
        return 0;
    decimal = decimal + (num % 10 * base);
    bintodec(num/10, x-1, base*2);
}