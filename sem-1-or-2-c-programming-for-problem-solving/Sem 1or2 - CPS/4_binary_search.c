#include<stdio.h>
int main() {
    int first, last, middle, array[100];
    int c, n, search;
    printf("\n Enter nummber of elements:");
    scanf("%d",&n);

    printf("\nEnter %d integers:", n);
    for(c=0; c<n; c++)
        scanf("%d", &array[c]);
        printf("\nEnter value to find:");
        scanf("%d", &search);
        first = 0;
        last = n-1;
        middle = (first + last)/2;

        while(first <= last){
            if(array[middle] < search)
                first = middle + 1;
            else if(array[middle] == search)
            {
                printf("%d found at location %d\n", search, middle+1);
                break;
            }
            else
                last = middle - 1;
            middle = (first + last)/2;
        }
        if(first > last)
            printf("\n Not found! %d isn't present in the list",search);
            return 0;
}