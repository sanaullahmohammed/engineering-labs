/*
Design, Develop and Implement a menu driven Program in C for the following operations on
Doubly Linked List (DLL) of Employee Data with the elds: SSN, Name, Dept, Designation,
Sal, PhNo
a. Create a DLL of N Employees Data by using end insertion.
b. Display the status of DLL and count the number of nodes in it
c. Perform Insertion and Deletion at End of DLL
d. Perform Insertion and Deletion at Front of DLL
e. Demonstrate how this DLL can be used as Double Ended Queue.
f. Exit
*/

#include <stdio.h>
#include <stdlib.h>
typedef struct NODE Node;
struct NODE
{
    char ssn[20];
    char name[20];
    char dept[20];
    char desig[20];
    int sal;
    char pno[12];
    Node *next;
    Node *prev;
};

Node *start = NULL;

Node *info()
{
    Node *s;
    s = malloc(sizeof(Node));
    printf("Enter s info [ssn Name Dept Desig Salary phone]: ");
    scanf("%s %s %s %s %d %s", s->ssn, s->name, s->dept, s->desig, &s->sal, s->pno);
    printf("%s %s %s %s %d %s", s->ssn, s->name, s->dept, s->desig, s->sal, s->pno);
    return(s);
}

void insert_front()
{
    Node *student;
    student = info();
    if(start == NULL)
    {
        student->next = NULL;
        student->prev = NULL;
        start = student;
        return;
    }
    student->next = start;
    student->prev = NULL;
    start->prev = student;
    start = student;
}

void insert_end()
{
    Node *p, *student;
    student = info();
    student->next = NULL;
    if(start == NULL)
    {
        start = student;
        student->prev = NULL;
        return;
    }
    p = start;
    while(p->next != NULL)
    {
        p = p->next;
    }
    p->next = student;
    student->prev = p;
}

void delete_front()
{
    Node *p;
    if(start == NULL)
    {
        printf("The DLL list is empty. \n");
        return;
    }
    if (start->next == NULL)
    {
        printf("Deleted Employee SSN is %s \n\n",start->ssn);
        free(start);
        start = NULL;
        return;
    }
    p = start;
    start = start->next;
    start->prev = NULL;
    printf("Deleted Employee SSN is %s \n\n", p->ssn);
    free(p);
}

void delete_end()
{
    Node *p, *q;
    if(start == NULL)
    {
        printf("The DLL list is empty. \n");
        return;
    }
    if(start->next == NULL)
    {
        printf("Deleted Employee SSN is %s \n\n",start->ssn);
        free(start);
        start = NULL;
        return;
    }
    p = start;
    while(p->next != NULL)
    {
        p = p->next;
    }
    q = p->prev;
    q->next = NULL;
    printf("Deleted Employee SSN is %s \n\n", p->ssn);
    free(p);
}

void display()
{
    int n=0;
    Node *p;
    p = start;
    while(p != NULL)
    {
        n++;
        printf("%d. %s %s %s %s %ld %s\n", n, p->ssn, p->name, p->dept, p->desig, p->sal, p->pno);
        p = p->next;
    }
}

void create()
{
    int n;
    printf("Enter number of Employees: ");
    scanf("%d", &n);
    for(int i=1; i <= n; i++)
    {
        printf("Employee %d details\n", i);
        insert_end();
    }
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
        {"Create", create},
        {"Insert front", insert_front},
        {"Insert end", insert_end},
        {"Delete front", delete_front},
        {"Delete end", delete_end},
        {"Display", display}
    };
    int size = sizeof(menu)/sizeof(Menu);
    for(;;)
    {
        printf("\n-------DLL Menu-------\n");
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
1. Display empty list
2. Insert S1, S2, S3
3. Display list S3, S2, S1
4. Insert S4
5. Display S3, S2, S1, S4
6. Delete S4
7. Display S3, S2, S1
8. Insert S4
9. Display S4, S3, S2, S1
*/