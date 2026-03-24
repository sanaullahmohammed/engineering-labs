/**
8.  Find Minimum Cost Spanning Tree of a given connected undirected graph using Kruskal'salgorithm. Use
Union-Find algorithms in your program.

KRUSKAL'S ALGORITHM  ----------  filename : kruskal

 */

import java.util.Scanner;

public class kruskal {

    int parent[]=new int[10]; 

    int find(int m)
    {
        int p=m;
        while(parent[p]!=0)
            p=parent[p];
        
        return p;
    }

    void union(int i,int j)
    {
        if(i<j)
             parent[i]=j;
        else
            parent[j]=i;
    }

    void krkl(int[][]a, int n)
    {
        int u=0, v=0, min, k=0, i, j, sum=0;
        while(k < n-1)
        {
            min = 99;
            for(i=1; i<=n; i++)
                for(j=1; j<=n; j++)
                    if(a[i][j] < min && i != j)
                    {
                        min=a[i][j];
                        u=i;
                        v=j;
                    }
            i=find(u);
            j=find(v);

            if(i!=j)
            {
                union(i,j);
                System.out.println("("+u+","+v+")"+"="+a[u][v]);
                sum=sum+a[u][v];
                k++;
            }

            a[u][v] = a[v][u] = 99;
        }

        System.out.println("The cost of minimum spanning tree = "+sum);
    }
    public static void main(String[] args) {

    int a[][]=new int[10][10]; 
    int i,j;
    System.out.println("Enter the number of vertices of the graph"); 
    Scanner sc = new Scanner(System.in);

    int n;
    n = sc.nextInt();
    System.out.println("Enter the wieghted matrix");
        for(i=1;i<=n;i++)
            for(j=1;j<=n;j++)
                a[i][j]=sc.nextInt();
    kruskal k = new kruskal(); 
    k.krkl(a,n);
    sc.close();
    }
}

/**
 OUTPUT : 
 Enter the number of vertices of the graph
6
Enter the wieghted matrix
0 3 99 99 6 5
3 0 1 99 99 4
99 1 0 6 99 4
99 99 6 0 8 5
6 99 99 8 0 2
5 4 4 5 2 0
(2,3)=1
(5,6)=2
(1,2)=3
(2,6)=4
(4,6)=5
The cost of minimum spanning tree = 15
 */