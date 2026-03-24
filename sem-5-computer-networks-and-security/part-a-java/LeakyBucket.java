import java.util.*;

public class LeakyBucket {

    int burst;  //incoming burst
    int size;   //bucket size
    int rate;   //outgoing rate

    int incoming;
    int pending;
    int overflow;
    int outgoing;

    LeakyBucket() 
    {
        incoming = 0;
        pending = 0;
        overflow = 0;
        outgoing = 0;
    }

    void leakyBucket() 
    {
        System.out.println("Time    Incoming    Pending     Overflow    Outgoing");

        Random rand  = new Random();
        int time = 0;

        while(time < 8)
        {
            incoming = rand.nextInt(burst);
            if((pending + incoming) > size)
            {
                overflow = (pending + incoming) - size;
                pending = size;
            }
            else 
            {
                pending += incoming;
            }

            output(time, incoming, pending, overflow, outgoing);
            outgoing = Math.min(rate, pending);

            pending -= outgoing;

            incoming = 0;
            ++time;
        }

    }

    void input()
    {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter the burst rate : ");
        burst = scanner.nextInt();

        System.out.print("Enter the bucket size : ");
        size = scanner.nextInt();

        System.out.print("Enter the outgoing rate : ");
        rate = scanner.nextInt();

        scanner.close();
    }

    void output(int time, int incoming, int pending, int overflow, int outgoing)
    {
        System.out.printf("%d\t%d\t%d\t%d\t%d\n",time, incoming, pending, overflow, outgoing);
    }

    public static void main(String[] args)
    {
        LeakyBucket lb = new LeakyBucket();

        lb.input();
        lb.leakyBucket();
    }
}