/*
Design, Develop and Implement a Program in C for converting an Infix Expression to Postx
Expression. Program should support for both parenthesized and free parenthesized expressions
with the operators: +, -, *, /, % (Remainder), ^(Power) and alphanumeric operands.
*/

#include <stdio.h>
#define SIZE 50

char s[SIZE];
int top= -1;

void push(char elem)
{
    s[++top] = elem;
}

char pop()
{
    return(s[top--]);
}
/*
1. Define precedences for the operators
2. The operators are +, -, *, /, ^
3. And lowest for '('
4. Return lowest as default.
*/

int precedence(char elem)
{
    switch(elem)
    {
        case '(': return 1;
        case '+':
        case '-': return 2;
        case '*':
        case '/':
        case '%': return 3;
        case '^': return 4;
        default: return 0;
    }
}
/*
1. Input is infix expression
2. Output is postfix expression
3. Push the marker '\0'
4. Handle parens, operators and operands
*/
void convert(char infix[], char postfix[])
{
    char ch;
    int k=0;
    push('\0'); // null marker
    for(int i=0; infix[i]; i++)
    {
        ch = infix[i];
        switch(ch)
        {
            case '(':
            push(ch);
                break;

            case ')':
            while((ch = pop()) != '(')
            {
                postfix[k++] = ch;
            }
                break;

            case '+':
            case '-':
            case '/':
            case '*':
            case '%':
            case '^':
                while(precedence(ch) <= precedence(s[top]))
                {
                    postfix[k++]=pop();
                }
                push(ch);
                    break;

            default:
                postfix[k++]=ch;
        }
    }
// empty stack into postfix
// Check if '\0' is at bottom of the stack

    while((postfix[k++] = pop()) != '\0');
}

/*
1. Declare infix and postfix arrays
2. Read infix expression
3. Convert infix to postfix expression
*/

int main()
{
    char infix[100];
    char postfix[100];

    printf("Enter the Infix Expression: ");
    gets(infix);

    convert(infix, postfix);
    printf("Postfix Expn: %s\n", postfix);
}

/*
Test cases
1. a*(b+c/d)-1 to abcd/+*1-
2. a+b+c-d to ab+c+d-
3. a^3*b to a3^b*
4. (a+b)*d+e/(f+a+d)+c to ab+d*efa+d+/+c+
5. ((a/(b-c+d))*(c-a)*c) to abc-d+/ca-c
*/