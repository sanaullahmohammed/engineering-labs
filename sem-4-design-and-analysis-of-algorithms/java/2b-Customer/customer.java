/*
2b. Write a Java class called Customer to store their name and date_of_birth. The date_of_birth
format should be dd/mm/yyyy. Write methods to read customer data as <name, dd/mm/yyyy>
and display as <name, dd, mm, yyyy> using StringTokenizer class considering the delimiter
character as “/”.

CUSTOMER ---------- filename : customer.java

The program gives compiler error but runs good
**/

import java.util.Scanner;
import java.util.StringTokenizer;
class customer
{
    String name;
    String date;

    public void read()
    {
        System.out.println("Enter the customer name and date");
        Scanner input =new Scanner(System.in);

        try{
        name = input.next();
        date = input.next();
        }
        finally{
            input.close();
        }
    }
    public void display()
    {
        System.out.print(name+",");
        String delims = "/";
        StringTokenizer st = new StringTokenizer(date,delims);

        while(st.hasMoreElements()) {
            System.out.print(st.nextElement()+",");
            }
        System.out.println();
    }   
    public static void main(String[] args)
    {
        System.out.println("Enter the customer detail");
        customer[] cus = new customer[30];
        Scanner sc = new Scanner(System.in);
        System.out.println("enter the number of customer");
        int n = sc.nextInt();

        for(int i = 0; i < n; i++)
        {
            cus[i] = new customer();
            cus[i].read();
        }

        for(int i = 0; i < n; i++)
            cus[i].display();
    sc.close();
    
    }
     

}