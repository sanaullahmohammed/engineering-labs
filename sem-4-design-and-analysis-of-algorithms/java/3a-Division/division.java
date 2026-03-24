/** 
3a. Write a Java program to read two integers a and b. Compute a/b and print, when b is not
zero. Raise an exception when b is equal to zero.

DIVISION ----------- filename : division.java
*/

import java.util.Scanner;
class division
    {
    public static void main(String[] args)
    {
        int a,b,result;
        Scanner input =new Scanner(System.in);
        System.out.println("Input two integers");
        a=input.nextInt();
        b=input.nextInt();
        try
        {
            result=a/b;
            System.out.println("Result="+result);
        }
        catch(ArithmeticException e)
        {
            System.out.println("exception caught: Divide by zero error"+e);
        }
        input.close();
    }
}

/**
 Input two integers
6 2
Result=3

Input two integers
3 0
exception caught: Divide by zero errorjava.lang.ArithmeticException: / by zero

 */