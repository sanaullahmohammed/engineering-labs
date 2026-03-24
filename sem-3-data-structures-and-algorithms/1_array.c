/*  Execution steps
1. gcc <filename>.c
2. ./<filename>.exe
*/


/*
Array

Design, Develop and Implement a menu driven Program in C for the following array operations.
a. Creating an array of N Integer Elements
b. Display of array Elements with Suitable Headings
c. Inserting an Element (ELEM) at a given valid Position (POS)
d. Deleting an Element at a given valid Position (POS)
e. Exit.
Support the program with functions for each of the above operations.
*/
#include <stdio.h>
#include <stdlib.h>
int a[20];
int n = 0;
/*
1. Prompt for array size (n).
2. Read n array elements
*/
void create()
{
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    printf("Enter the elements for the array:\n");
    for(int i=0; i<n; i++)
    {
        scanf("%d",&a[i]);
    }
}
/*
1. Print proper heading
2. print n array elements
*/
void display()
{
    printf("The array elements are:\n");
    for(int i=0; i<n; i++)
    {
        printf("%d\n",a[i]);
    }
}
/*
1. Prompt for pos
2. Read pos
3. Prompt for element value
4. Read the element
5. Shift right the elements n-1, n-2, .., pos
6. Insert a[pos] = value
7. Increment the array size n
*/
void insert()
{
    int pos, value;
    printf("Enter the index position for the new element: ");
    scanf("%d", &pos);
    printf("Enter the element to be inserted : ");
    scanf("%d", &value);
    for (int i=n-1; i>=pos; i--)
    {
        a[i+1]=a[i];
    }
    a[pos] = value;
    n=n+1;
}
/*
1. Prompt for pos
2. read pos
3. shift left the elements pos+1 ,..., n-1
4. Decrement the array size n
*/
void delete()
{
    int pos, value;
    printf("Enter the index position of the element to be deleted: ");
    scanf("%d", &pos);
    value = a[pos];
    for(int i=pos+1; i<n; i++)
    {
        a[i-1]=a[i];
    }
    n = n-1;
    printf("The deleted element is = %d",value);
}
/*
1. Define Menu type
2. Declare menu as an array variable of type Menu and initialize.
3. Print menu header
4. Display menu names
5. Prompt for choice
6. Read choice
7. Invoke the function corresponding to the choice menu[choice].func()
8. Repeat steps 5,6,7 for ever
*/
int main( )
{
    int choice;
    typedef struct
    {
        char *name;
        void (*func)();
    } Menu;
    Menu menu[] =
    {
        {"Done", exit },
        {"Create", create },
        {"Insert", insert },
        {"Delete", delete },
        {"Display", display}
    };
    for(;;)
    {
        printf("\n-------Array Menu-------\n");
        for(int i=0; i < 5; i++)
        {
            printf("%d. %s\n", i, menu[i].name);
        }
        printf("---------------------------------\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        menu[choice].func();
    }
}

/*
Test Cases.
---------- Menu ----------
1. Create
2. Display
3. Insert
4. Delete
5. Exit
Enter your choice: 1
1. Create array with data elements 2 4 6 8 10 and display
2. Insert 12 at pos=0 and display
3. Delete item at pos=5 and display
4. Exit
*/