/* 3b. Write a Java program that implements a multi-thread application that hash tree threads.
First thread generates a random integer for every 1 second; second thread computes the
square of the number and prints; third thread will print the value of cube of the number.
import java.util.*;

MUTITHREAD ------------ filename : multithread.java

*/

import java.util.*;

class second implements Runnable
{
    public int x;

    public second (int x)
    {
        this.x=x;
    }

    public void run()
    {
        System.out.println("Second thread : Square of the number is "+ x*x);
    }
}

class third implements Runnable
{
    public int x;

    public third(int x)
    {
        this.x=x;
    }

    public void run()
    {
        System.out.println("Third thread : Cube of the number is "+ x*x*x);
    }
}

class first extends Thread
{
    public void run()
    {
        int num=0;
        Random r = new Random();

        try
        {
            for(int i=0;i<5;i++)
            {
                num=r.nextInt(100);
                System.out.println("First thread generated number is "+num);
                Thread t2=new Thread (new second(num)); t2.start();
                Thread t3=new Thread(new third(num));
                t3.start();
                Thread.sleep(1000);
            }
        }
        catch(Exception e)
        {
            System.out.println(e.getMessage());
        }
    }
}

public class multithread
{
    public static void main(String args[])
    {
        first a=new first();
        a.start();
    }
}

/**
 First thread generated number is 81
Third thread : Cube of the number is 531441
Second thread : Square of the number is 6561
First thread generated number is 0
Second thread : Square of the number is 0
Third thread : Cube of the number is 0
First thread generated number is 73
Second thread : Square of the number is 5329
Third thread : Cube of the number is 389017
First thread generated number is 11
Second thread : Square of the number is 121
Third thread : Cube of the number is 1331
First thread generated number is 51
Second thread : Square of the number is 2601
Third thread : Cube of the number is 132651
 */