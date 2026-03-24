/* 
5. Sort a given set of n integer elements using Merge Sort method and compute its time
complexity. Run the program for varied values of n > 5000, and record the time taken to sort.
Plot a graph of the time taken versus n on graph sheet. The elements can be read from a file
or can be generated using the random number generator. Demonstrate using Java how the
divideand- conquer method works along with its time complexity analysis: worst case,
average case and best case.

MERGESORT ------------------  filename : mergesort.java

*/
import java.util.Random;
import java.util.Scanner;
/* MERGESORT save the file name as mergesort.java*/
public class mergesort{
    static int max=10000;
    void merge( int[] array,int low, int mid,int high)
    {
        int i=low;
        int j=mid+1;
        int k=low;
        int[]resarray;
        resarray=new int[max];
        while(i<=mid&&j<=high)
        {
            if(array[i]<array[j])
            {
                resarray[k]=array[i];
                i++;
                k++;
            }
            else
            {
                resarray[k]=array[j];
                j++;
                k++;
            }
        }
        while(i<=mid)
            resarray[k++]=array[i++];
        while(j<=high)
            resarray[k++]=array[j++];
        for(int m=low;m<=high;m++)
            array[m]=resarray[m];
    }
    void sort(int[] array, int low, int high)
    {
        if(low<high)
        {
            int mid=(low+high)/2;
            sort(array,low,mid);
            sort(array,mid+1,high);
            merge(array,low,mid,high);
        }
    }
    public static void main(String[] args){
        int[] array;
        int i;
        System.out.println("Enter the array size");
        Scanner sc =new Scanner(System.in);
        int n=sc.nextInt();
        array= new int[max];
        Random generator=new Random();
        for( i=0;i<n;i++)
            array[i]=generator.nextInt(20);
        System.out.println("Array before sorting");
        for( i=0;i<n;i++)
            System.out.println(array[i]+" ");
        long startTime=System.nanoTime();
        mergesort m = new mergesort();
        m.sort(array,0,n-1);
        long stopTime=System.nanoTime();
        long elapseTime=(stopTime-startTime);
        System.out.println("Time taken to sort  array is: "+elapseTime+" nanoseconds");
        System.out.println("Sorted array is");
        for(i=0;i<n;i++)
            System.out.println(array[i]);
        sc.close();
    }
}

/**
 * OUTPUT :
 Enter the array size
10
Array before sorting
5 
4 
18
6
13
13
14
14
19
14 
Time taken to sort  array is: 1873800 nanoseconds
Sorted array is
4
5
6
13
13
14
14
14
18
19
 */