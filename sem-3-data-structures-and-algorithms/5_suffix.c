/*
Design, Develop and Implement a Program in C for the following Stack Applications
a. Evaluation of Suffix expression with single digit operands and operators:
+, -, *, /, %, ^
b. Solving Tower of Hanoi problem with n disks
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <string.h>
#define SIZE 50 /* Size of Stack */

int stack[SIZE];
int top = -1;

void push(int elem)
{
    stack[++top]=elem;
}

int pop()
{
    return(stack[top--]);
}
/*
1. Input is postfix expression as string
1

Chapter 5. Expr 15CSL38
2. Push operands until the operator
3. evaluate exp with this operator and operands on the stack
4. Push the result on to the stack
*/
void suffix(char exp[])
{
    char ch;
    int i=0, op1, op2;
    for (int i=0; exp[i]; i++)
    {
        ch = exp[i];
        if (isdigit(ch))
        {
            push(ch-'0'); /* Push the operand */
            continue;
        }
/* Operator, pop two operands */
        op2 = pop();
        op1 = pop();

        switch(ch)
        {
            case '+':
            push(op1+op2);
            break;
            case '-':
            push(op1-op2);
            break;
            case '*':
            push(op1*op2);
            break;
            case '/':
            push(op1/op2);
            break;
            case '%':
            push(op1%op2);
            break;
            case '^': push(pow(op1,op2));
            break;
        }
    }
    printf("Result: %d, top=%d\n\n", stack[top], top);
}
/*
1. Inputs are number of disks and 3 pegs 'b', 'a', and 'e'
2. Base case when n = 1, move b -> e
3. when n=2, b -> e, b -> a, a -> e
*/
void tower(int n, char beg, char aux, char end)
{
    if(n == 1)
    {
        printf("%c --> %c\n", beg, end);
            return;
    }
    tower(n-1, beg, end, aux);
    tower(1, beg, aux, end);
    tower(n-1, aux, beg, end);
    // (2^n)-1 operations
}
/*
1. Evaluate postfix expression one or more times
2. Stop evaluation when the expressio is '.'
3. Solve tower of hanoi until the number diskes is 0
*/
int main()
{
    char exp[50];
    int n;
    printf("SUFFIX exression:\n");
    for (;;)
    {
        printf("Enter sufffix Expr [. to stop]: ");
        gets(exp);
        if (exp[0] == '.') break;
        suffix(exp);
    }
    printf("TOWER OF HANOI:\n");
    for (;;)
    {
        printf("Enter number of disks [0 to stop] : ");
        scanf("%d", &n);
        if (n == 0) break;
        printf("Sequence of moves involved in Tower of Hanoi are :\n");
        tower(n, 'b', 'a', 'e');
    }
    return 0;
}

/*
Test cases

1. 23+ is 5
2. 23- is -1
3. 23^1- is 7
Number of disks = 2

b --> a
b --> e
a --> e
*/