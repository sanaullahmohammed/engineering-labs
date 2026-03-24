/*
Design, Develop and Implement a Program in C for the following operations on Singly Circular
Linked List (SCLL) with header nodes
a. Represent and Evaluate a Polynomial P(x,y,z) = 6x2y2z-4yz5+3x3yz+2xy5z-2xyz3
b. Find the sum of two polynomials POLY1(x,y,z) and POLY2(x,y,z) and store the result in POLYSUM(x,y,z)
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
typedef struct NODE Node;
struct NODE
{
    int coef;
    int xpow;
    int ypow;
    int zpow;
    Node *next;
};
/*
1. Traverse the header list
2. Start node is head->next
3. Stop when head is reached
*/
void display(Node *head)
{
    Node *p;
    p = head->next;
    while (p != head)
    {
        char sign = p->coef < 0 ? '-' : '+';
        printf("%c%dx^%dy^%dz^%d", sign, abs(p->coef), p-> xpow, p-> ypow, p-> zpow);
        p = p->next;
    }
    printf("\n\n");
}
/*
1. Create the node and initialize its fields
2. Insert the node at the end of the header list
*/
void attach(Node *head, int coef, int xpow, int ypow, int zpow)
{
    Node *node = malloc(sizeof(Node));
    node->coef = coef;
    node->xpow = xpow;
    node->ypow = ypow;
    node->zpow = zpow;
    node->next = NULL;
    Node *p = head->next;
    while(p->next != head)
    {
        p = p->next;
    }
    node->next = head;
    p->next = node;
}
/*
1. Create header node
2. Get number of terms in the polynomial
3. Read data for each term
4. Attach the term to the given head
*/
Node *create()
{
    Node *head;
    int n;
    int coef, xpow, ypow, zpow;
    head = malloc(sizeof(Node));
    head->next = head;
    printf("Enter number of terms[0 if none]: ");
    scanf("%d", &n);
    for (int i=0; i<n; i++)
    {
        printf("Enter a term (coef, pows of x y z): ");
        scanf("%d%d%d%d", &coef, &xpow, &ypow, &zpow);
        attach(head, coef, xpow, ypow, zpow);
    }
    return(head);
}
/*
1. Create 3 circular lists with header nodes
2. Compare the terms of the two polynomials
3. Attach sum of the two polynomials as third polynomial:
Case 1: sum of two polynomial terms if the exponents are same
Case 2. 1st polynomial term if its x exponent is smaller
Case 3. 2nd polynomial term if its x exponent is smaller
4. Advance two next term in the polynomials based on the above cases
*/
void padd()
{
    Node *h1 = create();
    Node *h2 = create();
    Node *h3 = create();
    printf("Create two polynomials.\n\n");
    display(h1);
    display(h2);
    display(h3);
    Node *p1 = h1->next, *p2 = h2->next;
    while(p1 != h1 && p2 != h2)
    {
        if( p1->xpow==p2->xpow && p1->ypow == p2->ypow && p1->zpow == p2->zpow)
        {
            attach(h3, p1->coef + p2->coef, p1->xpow, p1->ypow, p1->zpow);
            p1 = p1->next;
            p2 = p2->next;
        }
        else if(p1->xpow < p2->xpow)
        {
            attach(h3, p1->coef, p1->xpow, p1->ypow, p1->zpow);
            p1 = p1->next;
        }
        else
        {
            attach(h3, p2->coef, p2->xpow, p2->ypow, p2->zpow);
            p2 = p2->next;
        }
        display(h3);
    }
    while(p1 != h1)
    {
        attach(h3, p1->coef, p1->xpow, p1->ypow, p1->zpow);
        p1 = p1->next;
    }
    while(p2 != h2)
    {
        attach(h3, p2->coef, p2->xpow, p2->ypow, p2->zpow);
        p2 = p2->next;
    }
    display(h3);
}
/*
1. Create the polynomial of n terms
2. Read the values for x, y and z
3. Evaluate the valu of each terminal too find the sum
*/
void pval()
{
    int x, y, z;
    int value;
    Node *head = create();
    printf("Enter x y z: ");
    scanf("%d%d%d", &x, &y, &z);
    value = 0;
    Node *p = head->next;
    while(p != head)
    {
        value = value + (p->coef*pow(x, p->xpow)*pow(y, p->ypow)*pow(z, p->zpow));
        p = p->next;
    }
    printf("Polynomial value = %d \n", value);
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
        {"Pval", pval},
        {"Padd", padd}
    };
    int size = sizeof(menu)/sizeof(Menu);
    for(;;)
    {
        printf("\n-------Menu-------\n");
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
1. P(x,y,z) = 6x2y2z - 4yz5 + 3x3yz + 2xy5z - 2xyz3
5
6 2 2 1 -4 0 1 5 3 3 1 1 2 1 5 1 -2 1 1 3
3 2 1
With x = 3, y = 2, z = 1 p(x,y,z) = 550
1. P1(x,y,z) = 6x2y2z - 4yz5 + 3x3y, P2(x,y,z) = +2xy5z - 2xyz3, P1+P2?
3 6 2 2 1 4 0 1 5 3 3 1 0
2 2 1 5 1 -2 1 1 3
*/

/*output
-------Menu-------
0. Done
1. Pval
2. Padd
---------------------------------
Enter your choice: 1
Enter number of terms[0 if none]: 5
Enter a term (coef, pows of x y z): 6 2 2 1
Enter a term (coef, pows of x y z): -4 0 1 5
Enter a term (coef, pows of x y z): 3 3 1 1
Enter a term (coef, pows of x y z): 2 1 5 1
Enter a term (coef, pows of x y z): -2 1 1 3 
Enter x y z: 3 2 1 
Polynomial value = 550 

-------Menu-------
0. Done
1. Pval
2. Padd
---------------------------------
Enter your choice: 2
Enter number of terms[0 if none]: 3
Enter a term (coef, pows of x y z): 6 2 2 1
Enter a term (coef, pows of x y z): -4 0 1 5 
Enter a term (coef, pows of x y z): 3 3 1 1
Enter number of terms[0 if none]: 2
Enter a term (coef, pows of x y z): 2 1 5 1
Enter a term (coef, pows of x y z): -2 1 1 3
Enter number of terms[0 if none]: 0
Create two polynomials.

+6x^2y^2z^1--4y^1z^5+3x^3y^1z^1

+2x^1y^5z^1--2x^1y^1z^3



+2x^1y^5z^1

+2x^1y^5z^1--2x^1y^1z^3

+2x^1y^5z^1--2x^1y^1z^3+6x^2y^2z^1--4y^1z^5+3x^3y^1z^1
*/