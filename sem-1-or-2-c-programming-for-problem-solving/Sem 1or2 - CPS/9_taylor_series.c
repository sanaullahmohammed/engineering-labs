#include<stdio.h>
#include<stdlib.h>
#include<math.h>

void main() {
    int n, i, j, f, k=1;
    double x, sum=0, z=0;

    printf("\n Sin(x)\n *********\n");
    printf("Enter the values of x and n:");  // x is in degrees, n is number of terms
    scanf("%lf%d", &x, &n);

    x = x*3.1428/180;

    for(i=1; i<=n; i+=2)
    {
        f = 1;
        for(j=1; j<=i; j++)
            f = f*j;
        sum = sum + (pow(x, i)/f) * k;
        k = -(k);
    }
    z = sin(x);
    printf("\nUser computation result = %2f", sum);
    printf("\nBuilt in function result = %2f", z);

    if(abs(sum-z) < 0.001)
        printf("\nBoth the results are equal");
    else
        printf("\n Both the results are not equal");
    
}

// gcc <filename>.c -lm