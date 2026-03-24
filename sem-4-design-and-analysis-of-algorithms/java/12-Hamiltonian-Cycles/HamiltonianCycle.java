/* 
12. Design and implement the presence of Hamiltonian Cycle in an undirected Graph G of n
    vertices.

HAMILTONIAN CYCLE --------- filename : HamiltonianCycle.java

**/

import java.util.*;

class HamiltoniancycleExp
{
    private int adj[][],x[],n;

    public HamiltoniancycleExp()
    {
        Scanner src = new Scanner(System.in);

        try{
        System.out.println("Enter the number of nodes");
        n = src.nextInt();
        x = new int[n];
        x[0] = 0;

        for (int i=1;i<n; i++)
            x[i] = -1;

        adj = new int[n][n];

        System.out.println("Enter the adjacency matrix");
            for (int i=0; i<n; i++)
                for (int j=0; j<n; j++)
                    adj[i][j] = src.nextInt();
        }
        finally{
            src.close();
        }
    }

    public void nextValue (int k)
    {
        int i=0;
        while(true)
        {
            x[k] = x[k]+1;

            if (x[k]==n)
                x[k]=-1;

            if (x[k]==-1)
                return;

            if (adj[x[k-1]][x[k]]==1)
                for (i=0; i<k; i++)
                    if (x[i]==x[k])
                        break;
                    if (i==k)
                        if (k<n-1 || k==n-1 && adj[x[n-1]][0]==1)
                            return;
        }
    }

    public void getHCycle(int k)
    {
        while(true)
        {
            nextValue(k);
            if (x[k]==-1)
                return; 
                if (k==n-1)
                {
                    System.out.println("\nSolution : ");
                    for (int i=0; i<n; i++)
                        System.out.print((x[i]+1)+" ");
                    System.out.println(1);
                }
            else getHCycle(k+1);
        }
    }
}
class HamiltonianCycle
{
    public static void main(String args[])
    {
            HamiltoniancycleExp obj = new HamiltoniancycleExp();
            obj.getHCycle(1);
    }
}

/**
 * Enter the number of nodes
6
Enter the adjacency matrix
0 1 1 1 0 0
1 0 1 0 0 1
1 1 0 1 1 0 
1 0 1 0 1 0 
0 0 1 1 0 1 
0 1 0 0 1 0

Solution :
1 2 6 5 3 4 1

Solution :
1 2 6 5 4 3 1

Solution :
1 3 2 6 5 4 1

Solution :
1 3 4 5 6 2 1

Solution :
1 4 3 5 6 2 1

Solution :
1 4 5 6 2 3 1
 */
