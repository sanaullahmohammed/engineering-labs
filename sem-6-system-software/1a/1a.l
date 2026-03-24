%{
#include<stdio.h>
int v=0,op=0,id=0,flag=0,i=0,j=0,k=0;
%}

%%
[0-9]+ {id++;printf("Identifier: %s\n",yytext);}
"+"|"-"|"*"|"/" {op++;printf("Operator: %s\n",yytext);}
"(" {v++;}
")" {v--;}
";" {flag=1;}
.;
%%

int main()
{
    printf("Enter the expression:");
    yylex();
    
    //"Press Ctrl+d to resume"
    
    if((op+1)==id && v==0 && flag==0)
    {
        printf("Expression is Valid\n");
        printf("No of identifier = %d \nNo of Operators = %d \n",id,op);
    }
    else
        printf("\n Expression is Invalid\n");
    return 0;
}