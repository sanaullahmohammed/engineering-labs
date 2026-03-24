#include<stdio.h>
#include<stdlib.h>

int a[10][10], b[10][10], c[10][10];

void main() {
    int m, n, p, q;
    int i, j, k;
    printf("------------Matrix Multiplication--------------\n");

    a:
    printf("Order of matrix should not be greater than 3 x 3\n");
    printf("Enter the order of First Matrix:");
    sacnf("%d%d", &m, &n);
    if(m>3 || n>3)
    goto a;

    b:
    printf("Order of matrix should not be greater than 3 x 3\n");
    printf("Enter the order of First Matrix:");
    sacnf("%d%d", &p, &q);
    if(p>3 || q>3)
    goto b;

    if(n != p) {
        printf("Order mismatch. Matrix Multiplication can't be performed");
    exit(0);
    }

    printf("\nEnter the elements of first matrix\n");
    for(i=0; i<m; i++)
        for(j=0; j<n; j++)
            scanf("%d",&a[i][j]);
    printf("\nEnter the elements of second matrix\n");
    for(i=0; i<p; i++)
        for(j=0; j<q; j++)
            scanf("%d", &b[i][j]);
    
    for(i=0; i<m; i++) {
        for(j=0; j<n; j++) {
            c[i][j] = 0;
            for(k=0; k<n; k++) {
                c[i][j] = c[i][j] + a[i][k] * b[k][j];
            }
        }
    }
    printf("\nGiven First Matrix is\n");
    for(i=0; i<m; i++) {
        for(j=0; j<n; j++)
            printf("%4.2d", a[i][j]);
    printf("\n");
    }

    printf("\nGiven Second Matrix\n");
    for(i=0; i<p; i++) {
        for(j=0; j<q; j++)
            printf("%4.2d",b[i][j]);
    printf("\n");
    }

    printf("Resultant Matrix is\n");
    for(i=0; i<m; i++) {
        for(j=0; j<q; j++)
            printf("%42d", c[i][j]);
    printf("\n");
    }
}
