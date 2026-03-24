/*  Execution steps
1. gcc <filename>.c
2. ./<filename>.exe
*/

/*
Strings

Design, Develop and Implement a Program in C for the following operations on Strings
a. Read a main string(STR), a pattern string(PAT) and a replace string (REP)
b. Perform Pattern Matching Operation : Find and replace al  occurences of PAT in STR with REP if PAT exists in STR. 
    Report suitable messages in case PAT does not exist in string
*/

// Pattern Matching can also be done through KMP algorithm; Here, naive algorithm is used :)
#include<stdio.h>
#include<string.h>

void delete(char t[], int pos, char p[])
{
    int m = strlen(p);
    int n = strlen(t);
    for(int i=0; i<m; i++)
    {
        for(int j = pos+1; j<=n; j++)
        {
            t[j-1] = t[j];
        }
        n = n-1;
    }
}

void insert(char t[], int pos, char r[])
{
    int m = strlen(r);
    int n = strlen(t);
    for(int i=0; i<m; i++)
    {
        for(int j = n; j>=pos; j--)
        {
            t[j+1] = t[j];
        }
        t[pos] = r[i];
        n = n+1;
        pos = pos + 1 ;
    }
}

void pattern(char t[], char p[], char r[])
{
    int i;
    int n = strlen(t);
    int m = strlen(p);
    for(int s=0; s < n-m+1; s++)
    {
        for(i=0; i<m; i++)
        {
            if(p[i] != t[s+i]) break;
        }
        if(i == m)
        {
            printf("pattern occur at the position %d \n", s);
            delete(t, s, p);
            insert(t, s, r);
        }
    }
}

int main() {
    char t[50], p[10], r[10];

    printf("Enter t: ");
    gets(t);

    printf("Enter p: ");
    gets(p);

    printf("Enter r: ");
    gets(r);

    pattern(t, p, r);

    printf("t : %s\n", t);
}