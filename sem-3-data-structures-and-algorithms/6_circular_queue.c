/*
Design, Develop and Implement a menu driven Program in C for the following operations on
Circular QUEUE of Characters (Array Implementation of Queue with maximum size MAX)
a. Insert an Element on to Circular QUEUE
b. Delete an Element from Circular QUEUE
c. Demonstrate Overflow and Underflow situations on Circular QUEUE
d. Display the status of Circular QUEUE
e. Exit
*/

#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 5

int cq[MAXSIZE] = {0, 0, 0, 0, 0};
int front = 0, rear = 0;
/*
1. Read the item
2. Check if the queue is full i.e r+1 = f
3. increment as r = r+1 % MAXSIZE
4. Add the item
*/
void insert()
{
    int item;
    printf("Enter item: ");
    scanf("%d", &item);
    if ((rear + 1) %MAXSIZE == front)
    {
        printf("Circular queue is full.\n");
        return;
    }
    rear = (rear+1) % MAXSIZE;
    cq[rear] = item;
}
/*
1. Check if queue is empty i.e f = r
2. Increment front as f = f+1 % MAXSIZE
*/
void delete()
{
    int item;
    if (rear == front)
    {
        printf("Circular queue is empty.\n");
        return;
    }
    front = (front + 1) % MAXSIZE;
    item = cq[front];
}
/*
1. Print the items from f+1 to r
*/
void display()
{
    int n;
    printf("front = %d, rear = %d, Queue = ", front, rear);
    int i=front;
    for(;;)
    {
        if (i == rear) break;
        i = (i+1) % MAXSIZE;
        printf("%d ", cq[i]);
    }
    printf("\n");
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
        {"Insert", insert},
        {"Delete", delete},
        {"Display", display}
    };

    int size = sizeof(menu)/sizeof(Menu);
    for(;;)
    {
        printf("\n-------CQ Menu-------\n");
        for(int i=0; i < size; i++)
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
Test cases
1. Insert 1 2 3 4 one at a time and verify using display
2. Insert 5, Queue Full
CSE 3 of 4

Chapter 6. CQueue 15CSL38
3. Delete
4. Display 2 3 4
5. Insert 5
6. Display 2 3 4 5
7. Delete 2 3 4 5 one at a time
8. Delete any further should show empty
*/