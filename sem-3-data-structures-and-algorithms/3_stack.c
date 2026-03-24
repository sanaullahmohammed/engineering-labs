/*
Design, Develop and Implement a menu driven Program in C for the following operations on
STACK of Integers (Array Implementation of Stack with maximum size MAX)
a. Push an Element on to Stack
b. Pop an Element from Stack
c. Demonstrate how Stack can be used to check Palindrome
d. Demonstrate Overflow and Underflow situations on Stack
e. Display the status of Stack
f. Exit
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 5
int stack[SIZE];
int top = -1;
/*
1. Input is item
2. Check stackfull condition
3. Increment top
4. Store item in the stack
*/
void push(int item)
{
    if (top != SIZE-1)
    {
        stack[++top]=item;
    }
    else printf("Stack Overflow\n");
}
/*
1. Output is item
2. Check stack empty condition
3. Remove item in the stack
4. Decrement the top
*/
int pop()
{
    if (top != -1)
    {
        return(stack[top--]);
    }
    else printf("Stack Underflow\n");
}
/*
1. Check stack empty condition
2. Print all the items on the stack
*/
void display()
{
    if (top == -1)
    {
        printf("Stack EMPTY\n");
         return;
    }
    printf("The Stack status is \n");
    for(int i=top; i >= 0; i--)
    {
        printf("%d\n", stack[i]);
    }
}
/*
1. Read a number
2. Convert number to string 's'
3. Push the string chars on to the stack
4. Pop the stack chars into 'r'
5. Compare 's' and 'r' to decide palindrome
*/
void palindrome()
{
    int n;
    char s[10];
    char r[10];
    printf("Enter number for palindrome check: ");
    scanf("%d", &n);
    sprintf(s, "%d", n);
    for (int i=0; s[i] != '\0'; i++)
    {
        push(s[i]);
    }
    for (int i=0; s[i] != '\0'; i++)
    {
        r[i] = pop();
        r[i+1] = '\0';
    }
    printf("s = %s, p = %s\n", s, r);
    if (strcmp(s, r) == 0)
        printf("Palindrome number\n");
    else
    printf("Not Palindrome number \n");
}
/*
1. Read and push the item
*/
void insert()
{
    int item;
    printf("Enter item to be pushed: ");
    scanf("%d", &item);
    push(item);
}
/*
1. Pop and print the item
*/
void delete()
{
    int item;
    item = pop();
    printf("Popped element is %d\n", item);
}

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
        {"Done", exit},
        {"Push", insert},
        {"Pop", delete},
        {"Display", display},
        {"Palindrome", palindrome}
    };

    int size = sizeof(menu)/sizeof(Menu);
    for(;;)
    {
        printf("\n-------Stack Menu-------\n");
        for(int i=0; i < size; i++)
        {
            printf("%d. %s\n", i, menu[i].name);
        }
        printf("---------------------------------\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        fflush(stdin);
        if (choice < size)
        {
            menu[choice].func();
        }
        else printf("Invalid choice:\n");
    }
return 0;
}

/*
Test cases
1. pop() results in Underflow
2. push() 5 elements, for 6th element the result is Overflow
3. push(10)
4. palindrome 252
5. Display stack with 10 (contents before palindrome)
*/