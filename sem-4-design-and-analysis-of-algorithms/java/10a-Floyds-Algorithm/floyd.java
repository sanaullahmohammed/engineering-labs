/*
 10 . Write Java programs to
    (a) Implement All-Pairs Shortest Paths problem using Floyd's algorithm

    FLOYD'S ALGORITHM ------------ filename : floyd.java
**/

import java.util.Scanner;

public class floyd {
    void flyd(int[][] w,int n)
    {
        int i,j,k;
        for(k=1;k<=n;k++)
            for(i=1;i<=n;i++)
                for(j=1;j<=n;j++)
                    w[i][j] = Math.min(w[i][j], w[i][k]+w[k][j]);
    }
    public static void main(String[] args) {
        int a[][]=new int[10][10]; 
        int n,i,j;
        System.out.println("enter the number of vertices"); 
        Scanner sc=new Scanner(System.in);
        n = sc.nextInt();
        System.out.println("Enter the weighted matrix");
        for(i=1;i<=n;i++)
            for(j=1;j<=n;j++)
                a[i][j]=sc.nextInt(); 
                
        floyd f=new floyd();
        f.flyd(a, n);
        System.out.println("The shortest path matrix is");
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=n;j++)
            {
                System.out.print(a[i][j]+" ");
            }
            System.out.println();
        }
        sc.close();
    }
}

/**
 OUTPUT :
 enter the number of vertices
4
Enter the weighted matrix
0 99 3 99
2 0 99 99
99 7 0 1
6 99 99 0
The shortest path matrix is
0 10 3 4
2 0 5 6
7 7 0 1
6 16 9 0
 */