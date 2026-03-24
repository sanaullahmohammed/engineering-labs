/* 4. Sort a given set of n integer elements using Quick Sort method and compute its time
complexity. Run the program for varied values of n > 5000 and record the time taken to sort.
Plot a graph of the time taken versus n on graph sheet. The elements can be read from a file
or can be generated using the random number generator. Demonstrate using Java how the
divide -and- conquer method works along with its time complexity analysis: worst case,
average case and best case.

QUICK SORT --- filename : quicksort.java
*/
import java.util.Random;
import java.util.Scanner;

public class quicksort {
    static int max=2000;

    int partition (int[] a, int low,int high)
    {
        int p,i,j,temp;
        p = a[low];
        i = low+1; 
        j = high;

        while(low < high)
        {
            while(a[i] <= p && i < high)
                i++;
            while(a[j] > p)
                j--;
        //}
            if(i<j)
            {
                temp=a[i];
                a[i]=a[j];
                a[j]=temp;
            }
            else
            {
                temp=a[low];
                a[low]=a[j];
                a[j]=temp;
                return j;
            }
        }
        return j;
        
    }

    void sort(int[] a,int low,int high)
    {
        if(low < high)
        {
            int s = partition(a,low,high);
            sort(a,low,s-1);
            sort(a,s+1,high);
        }
    }
    public static void main(String[] args) {

        int[] a;
        int i;

        System.out.println("Enter the array size");
        Scanner sc = new Scanner(System.in);
        try {
            int n = sc.nextInt();

            a = new int[max];
            Random generator=new Random();

            for( i=0;i<n;i++) 
                a[i]=generator.nextInt(20);

            System.out.println("Array before sorting ");
            for( i=0;i<n;i++) 
                System.out.print(a[i]+" "); 

            long startTime=System.nanoTime();
            quicksort m = new quicksort();
            m.sort(a,0,n-1);
            long stopTime=System.nanoTime(); 
            long elapseTime = (stopTime -startTime);
            
            System.out.println("Time taken to sort array is: "+ elapseTime +" nanoseconds");

            System.out.println("Sorted array is ");
            for(i=0;i<n;i++)
                System.out.println(a[i]);
        }
        finally {
            sc.close(); 
        }

    }
}

/**
 OUTPUT :
 Enter the array size
10
Array before sorting 
10 1 18 13 9 5 5 14 2 19 Time taken to sort array is: 30300 nanoseconds
Sorted array is 
1
2
5
5
9
10
13
14
18
19
 */