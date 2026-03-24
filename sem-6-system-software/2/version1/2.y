%{
#include<stdio.h>
#include<stdlib.h>

int yyerror();
int yylex();
int yyparse();
void some();

int c=0,n;
%}

%token A B
%%
input:s'\n' {some();}
s: A s1 B {c++;}| B s1: ; | A s1 {c++;}
%%


void main()
{
    printf("Enter A String\n");
    yyparse();
}


void some()
{
    printf("Enter n:\n");
    scanf("%d",&n);
    
    if(n==c)
    {
        printf("Valid\n");
        exit(0);
    }
    
    if(n!=c)
    {
        printf("Invalid string\n");
        exit(0);
    }
}

int yyerror()
{
    printf("Invalid string\n");
}
