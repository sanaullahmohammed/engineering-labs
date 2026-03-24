/*
1. a. Create a Java class called Student with the following details as variables within it.
(i) USN
(ii) Name
(iii) Branch
(iv) Phone
Write a Java program to create nStudent objects and print the USN, Name, Branch, and Phoneof these
objects with suitable headings.

STUDENT INFORMATION --------- filename : student.java
*/

import java.util.Scanner;
public class student {
    String USN;
    String Name;
    String branch;
    int phone;

    void insertRecord(String reg,String name, String brnch,int ph)
    {
        USN=reg;
        Name=name;
        branch=brnch;
        phone=ph;
    }

    void displayRecord()
    {
        System.out.println(USN+" "+Name+" "+branch+" "+phone);
    }
    public static void main(String args[]){
        student s[]=new student [100];
        Scanner sc = new Scanner(System.in);
        System.out.println("enter the number of students");
        int n = sc.nextInt();
        for(int i=0;i<n;i++)
        s[i]=new student();
        for(int j=0;j<n;j++)
        { 
            System.out.println("enter the usn,name,branch,phone");
            String USN=sc.next();
            String Name=sc.next();
            String branch=sc.next();
            int phone=sc.nextInt();
            s[j].insertRecord(USN,Name,branch,phone);
        }

        for( int m=0;m<n;m++)
        {
            s[m].displayRecord();
        }
        sc.close();
    }
}

/**
 * OUTPUT :
 enter the number of students
2
enter the usn,name,branch,phone
1 ashwini cse 93411
enter the usn,name,branch,phone
12 pragna ece 98562
1 ashwini cse 93411
12 pragna ece 98562
 */