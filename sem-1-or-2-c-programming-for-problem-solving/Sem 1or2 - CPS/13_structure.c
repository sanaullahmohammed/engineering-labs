/*Implement structures to read, write, compute average marks and the students
    scoring above and below the average marks for a class of N students*/

#include<stdio.h>
#include<stdlib.h>

struct stud{
    int rollno, marks, tol;
    char name[10];
}s[10];

void main ()
{
    int i, n;
    int total_marks = 0;
    float average;
    printf("Enter the number of students:\n");
    scanf("%d", &n);
    for(i=0; i<n; i++)
    {
        printf("Enter the roll number:\n");
        scanf("%d", &s[i].rollno);
        printf("Enter the name:\n");
        scanf("%s", &s[i].name);
        printf("Enter the marks obtained:\n");
        scanf("%d", &s[i].marks);

        total_marks = total_marks + s[i].marks;
    }
    average = total_marks / n;
    printf("Total marks = %d\n", total_marks);
    printf("Average marks = %f\n", average);

    printf("Details of students scoring marks above average:\n");
     printf("Roll No.\t Name\t Marks\n");
    for(i=0; i<n; i++)
    {
        if(s[i].marks >= average)
            printf("%d\t\t%s\t\t%d\n",s[i].rollno, s[i].name, s[i].marks);
    }
    printf("Details of students scoring marks below average:\n");
     printf("Roll No.\t Name\t Marks\n");
    for(i=0; i<n; i++)
    {
        if(s[i].marks < average)
            printf("%d\t\t%s\t\t%d\n",s[i].rollno, s[i].name, s[i].marks);
    }
}