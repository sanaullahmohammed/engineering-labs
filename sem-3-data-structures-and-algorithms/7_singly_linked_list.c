/*
Design, Develop and Implement a menu driven Program in C for the following operations on
Singly Linked List (SLL) of Student Data with the elds: USN, Name, Branch, Sem, PhNo
a. Create a SLL of N Students Data by using front insertion.
b. Display the status of SLL and count the number of nodes in it
c. Perform Insertion / Deletion at End of SLL
d. Perform Insertion / Deletion at Front of SLL(Demonstration of stack)
e. Exit
*/

#include <stdio.h>
#include <stdlib.h>
typedef struct NODE Node;
struct NODE
{
    char usn[10];
    char name[20];
    char branch[10];
    char sem[10];
    char pno[10];
    Node *next;
};

Node *start = NULL;
int flag=0; /* is 1 when list is created */
Node *info()
{
    Node *s;
    s = malloc(sizeof(Node));
    printf("Enter s info [USN Name Branch Semester phone]: ");
    scanf("%s %s %s %s %s", s->usn, s->name, s->branch, s->sem, s->pno);
    return(s);
}

void insert_front()
{
    Node *student;
    student = info();
    if (start == NULL)
    {
        student->next = NULL;
        start = student;
        return;
    }
    student->next = start;
    start = student;
}

void insert_end()
{
    Node *p, *student;
    student = info();
    student->next = NULL;
    if (start == NULL)
    {
        start = student;
        return;
    }
    p = start;
    while(p->next != NULL)
    {
        p = p->next;
    }
    p->next = student;
}


void delete_front()
{
    Node *p;
    if (start == NULL)
    {
        printf("The list is empty. \n");
        return;
    }
    p = start;
    start = start->next;
    printf("Deleted Student USN is %s \n\n", p->usn);
    free(p);
}

void delete_end()
{
    Node *p, *q;
    if (start == NULL)
    {
        printf("The list is empty. \n");
        return;
    }
    if (start->next == NULL)
    {
        printf("Deleted Student USN is %s \n\n", start->usn);
        start=NULL;
        free(start);
        return;
    }
    p = start;
    while (p->next != NULL)
    {
        q = p;
        p = p->next;
    }
    q->next = p->next;
    printf("Deleted Student USN is %s \n\n", p->usn);
    free(p);
}

void display()
{
    Node *p;
    int n;
    p = start;
    n = 1;
    while(p != NULL)
    {
        printf("%d. %s %s %s %s %s\n", n, p->usn, p->name, p->branch, p->sem, p->pno);
        p = p->next;
        n++;
    }
}

void create()
{
    int n;
    printf("Enter number of students: ");
    scanf("%d", &n);
    for(int i=1; i <= n; i++)
    {
        printf("Student %d details\n", i);
        insert_front();
    }
}


int main()
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
        printf("\n-------SLL Menu-------\n");
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
2. Insert U1, U2, U3
3. Display list U3, U2, U1
4. Insert U4
5. Display U3, U2, U1, U4
6. Delete U4
7. Display U3, U2, U1
8. Insert U4
9. Display U4, U3, U2, U1
*/