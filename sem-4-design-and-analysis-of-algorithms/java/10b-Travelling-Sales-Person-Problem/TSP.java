/**
 10. Write Java programs to
(b) Implement Travelling Sales Person problem using Dynamic programming.

TRAVELLING SALESMAN PROBLEM -------- filename : TSP.java

This Program uses Dynamic Programming Approach

 */

import java.util.Scanner;

class TSPExp {

    int weight[][], n, tour[], finalCost;
    final int INF=1000;

    TSPExp()
    {
        Scanner s = new Scanner(System.in);
        try
        {
            System.out.println("Enter no. of nodes:=>");
            n = s.nextInt();
            weight = new int[n][n];
            tour = new int[n-1];
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<n;j++)
                {
                    if(i!=j)
                    {
                        System.out.print("Enter weight of "+(i+1)+" to "+(j+1)+":=>");
                        weight[i][j]=s.nextInt();
                    }
                }
            }
            System.out.println();
            System.out.println("Starting node assumed to be node 1.");
            eval();
        }
        finally
        {
            s.close();
        }
    }

    public int COST(int currentNode,int inputSet[],int setSize)
    {
        if(setSize==0)
            return weight[currentNode][0];

            int min=INF;
            int setToBePassedOnToNextCallOfCOST[]=new int[n-1];
            for(int i=0;i<setSize;i++)
            {
                int k=0;//initialise new set
                for(int j=0;j<setSize;j++)
                {
                    if(inputSet[i]!=inputSet[j])
                    setToBePassedOnToNextCallOfCOST[k++]=inputSet[j];
                }
            int temp=COST(inputSet[i],setToBePassedOnToNextCallOfCOST,setSize-1);
            if((weight[currentNode][inputSet[i]]+temp) <min)
            {
                min=weight[currentNode][inputSet[i]]+temp;
            }
        }
        return min;
    }

    public int MIN(int currentNode,int inputSet[],int setSize)
    {
        if(setSize==0)
            return weight[currentNode][0];

        int min=INF,minindex=0;
        int setToBePassedOnToNextCallOfCOST[]=new int[n-1]; 
        for(int i=0; i<setSize; i++)//considers each node ofinputSet
        {
            int k=0;
            for(int j=0;j<setSize;j++)
            {
                if(inputSet[i]!=inputSet[j])
                setToBePassedOnToNextCallOfCOST[k++]=inputSet[j];
            }
            int temp = COST(inputSet[i],setToBePassedOnToNextCallOfCOST,setSize-1);
            if((weight[currentNode][inputSet[i]]+temp) < min)
            {
                min=weight[currentNode][inputSet[i]]+temp;
                minindex=inputSet[i];
            }
        }
        return minindex;
    }

    public void eval()
    {
        int dummySet[]=new int[n-1];
        for(int i=1; i<n; i++)
            dummySet[i-1]=i;
        finalCost  =COST(0,dummySet,n-1);
        constructTour();
    }

    public void constructTour()
    {
        int previousSet[]=new int[n-1];
        int nextSet[]=new int[n-2]; 
        
        for(int i=1;i<n;i++)
            previousSet[i-1]=i;
        int setSize=n-1;
        tour[0] = MIN(0,previousSet,setSize);

        for(int i=1; i<n-1; i++)
        {
            int k=0;
            for(int j=0; j<setSize; j++)
            {
                if(tour[i-1]!=previousSet[j])
                nextSet[k++]=previousSet[j];
            }
            --setSize;
            tour[i]=MIN(tour[i-1],nextSet,setSize); 
            for(int j=0;j<setSize;j++) 
                previousSet[j]=nextSet[j];
        }
        display();
    }

    public void display()
    {   
        System.out.println(); System.out.print("The tour is 1-"); 
        for(int i=0; i<n-1; i++)
            System.out.print((tour[i]+1)+"-");
        System.out.print("1"); 
        System.out.println();
        System.out.println("The final cost is "+ finalCost);
    }
}

class TSP
{
    public static void main(String args[])
    {
        new TSPExp();
    }
}

/**
 OUTPUT :
 Enter no. of nodes:=>
4
Enter weight of 1 to 2:=>2
Enter weight of 1 to 3:=>5
Enter weight of 1 to 4:=>7
Enter weight of 2 to 1:=>2
Enter weight of 2 to 3:=>8
Enter weight of 2 to 4:=>3
Enter weight of 3 to 1:=>5
Enter weight of 3 to 2:=>8
Enter weight of 3 to 4:=>1
Enter weight of 4 to 1:=>7
Enter weight of 4 to 2:=>3
Enter weight of 4 to 3:=>1

Starting node assumed to be node 1.

The tour is 1-2-4-3-1
The final cost is 11
 */