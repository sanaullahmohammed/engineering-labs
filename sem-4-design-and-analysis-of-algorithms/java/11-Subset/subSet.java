/* 
11. Design and implement in Java to find a subset of a given set S = {Sl, S2,. ,Sn} of n
    positive integers whose SUM is equal to a given positive integer d. For example, if S ={1, 2,
    5,6, 8} and d= 9, there are two solutions {1,2,6}and {1,8}. Display a suitable message, if the
    given problem instance doesn't have a solution.

    SUM OF SUBSET --------- filename : subSet.java
**/

import java.util.Scanner;


public class subSet {

    void subset(int num,int n, int x[])
    {
        int i;
        for(i=1; i<=n; i++)
            x[i] = 0;
        for(i=n; num!=0; i--)
        {
            x[i] = num % 2;
            num = num/2;
        }
    }
    public static void main(String[] args) {

        int a[] = new int[10];
        int x[] = new int[10];
        int n,d,sum,present = 0;
        int j;

        System.out.println("enter the number of elements of set");
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();

        System.out.println("enter the elements of set");
        for(int i=1;i<=n;i++)
            a[i]=sc.nextInt();

        System.out.println("enter the positive integer sum");
        d = sc.nextInt();
        if(d>0)
        {
            for(int i=1;i<=Math.pow(2,n)-1;i++)
            {
                subSet s=new subSet();
                s.subset(i,n,x);
                sum=0;

                for(j=1; j<=n; j++)
                    if(x[j]==1)
                        sum=sum+a[j];

                if(d==sum)
                {
                    System.out.print("Subset={");
                    present=1;

                    for(j=1;j<=n;j++)
                        if(x[j]==1)
                            System.out.print(a[j]+",");

                    System.out.print("} = "+d);
                    System.out.println();
                }
            }
        }

        if(present==0)
            System.out.println("Solution does not exists");
        
        sc.close();
    }
}

/**
 OUTPUT :
 enter the number of elements of set
5
enter the elements of set
1 2 5 6 8
enter the positive integer sum
9
Subset={1,8,} = 9
Subset={1,2,6,} = 9
 */