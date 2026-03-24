/*Optimized Implementation of Bubble Sort*/

#include <stdio.h>
int main()
{
    int array[100], n, i, j, swap,flag=0;
    printf("Enter number of elementsn");
    scanf("%d", &n);
    printf("Enter %d Numbers:n", n);
    for(i = 0; i < n; i++)
        scanf("%d", &array[i]);
    for(i = 0 ; i < n - 1; i++)
    {
        for(j = 0 ; j < n-i-1; j++)
        {
            if(array[j] > array[j+1])
            {
                swap = array[j];
                array[j] = array[j+1];
                array[j+1] = swap;
                flag=1;
            }
            if(!flag)
            {
                break;
            }
        }
    }

    printf("Sorted Array:n");
    for(i = 0; i < n; i++)
    printf("%dn", array[i]);
    
    return 0;
}

/* The execution of this program is similar to that of the normal bubble sort but, the only change is flag variable. 
The flag variable is set to one if there is a swap. This means that the array still requires more checking. 
If the flag is not 1 then we exit from the loop thinking that the array is already sorted.*/