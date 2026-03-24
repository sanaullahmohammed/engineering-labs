/**
 6. Implement in Java, the 0/1 Knapsack problem using
(b)Greedy method.

FRACTIONAL KNAPSACK ----------- filename : knapsackGreedy.java

 */
//import java.util.Random;
import java.util.Scanner;

public class knapsackGreedy {
    public static void main(String[] args){
        int i, j=0, max_qty, m, n;
        float sum = 0, max;

        Scanner sc = new Scanner(System.in);

        try {
            int array[][] = new int[2][20]; 
            System.out.println("Enter no of items"); 
            n = sc.nextInt();
            System.out.println("Enter the weights of each items");
            for(i=0; i<n; i++)
                array[0][i] = sc.nextInt();
            System.out.println("Enter the values of each item: ");
            for(i=0; i<n; i++)
                array[1][i] = sc.nextInt();
            System.out.println("Enter volume of knapsack: ");
            max_qty = sc.nextInt();
            m = max_qty;

            while(m>0)
            {
                max = 0;
                for(i=0; i<n; i++)
                {
                    if(((float)array[1][i])/((float)array[0][i])>max)
                    {
                        max=((float)array[1][i])/((float)array[0][i]);
                        j=i;
                    }
                }
                if(array[0][j] > m)
                {
                    System.out.println("Quantity of item number: "+(j+1) + " added is " +m);
                    sum+=m*max;
                    m=-1;
                }
                else
                {
                    System.out.println("Quantity of item number: " + (j+1) + " added is " + array[0][j]);
                    m-=array[0][j];
                    sum+=(float)
                    array[1][j];
                    array[1][j]=0;
                }
            }
            System.out.println("The total profit is " + sum); 
        }
        finally {
            sc.close();
        }
    }
}

/**
 OUTPUT :
 Enter no of items
4
Enter the weights of each items
2 1 3 2
Enter the values of each item:
12 10 20 15
Enter volume of knapsack:
5
Quantity of item number: 2 added is 1
Quantity of item number: 4 added is 2
Quantity of item number: 3 added is 2
The total profit is 38.333332
 */