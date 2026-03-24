/**
 * RSA: Rivest, Shamir, and Adelman
1. Find n
Choose two large prime numbers, a and b, and derive n = ab.
2. Find x.
Select encryption key x such that x and (a - 1)(b - 1) are relatively prime.
3. Find y.
Calculate decryption key y such that y is inverse of x,
xy mod (a-1)(b-1) = 1
4. The public key = {x, n}.
5. The private key = {y, n}.
6. Encryption: C = P(M) = M^x(mod n); Decryption: M = S(C) = C^y(mod n)

 */

import java.util.Scanner;
//import java.lang.Math;

public class RSA {
    int x;
    int y;
    int n; // S(d,n), P(e,n)

    String T;
    // gcd(m,n) = gcd(n, m%n)
    int gcd(int m, int n)
    {
        int rv = (n == 0 ? m : gcd(n, m % n));
        return rv;
    }

    // a^m % n
    int pow(int a, int m, int n)
    {
        int r = 1;
        while (m-- != 0)
            r = (r*a) % n;

        return r ;
    }

    // int pow(int a, int m, int n)
    // {
    //     int r = (int)Math.pow(a, m) % n;
    //     return r;
    // }

    void rsa()
    {
        int a;
        int b;
        int z;
        //odd prime numbers 3, 5 (3, 11?)
        a = 11;
        b = 13;

        n = a*b;
        z = (a-1)*(b-1);

        // choose e as relative prime
        for (x=2; gcd(x, z) != 1; x++);

        // choose d as inverse of e
        for (y=2; (y*x) % z != 1; y++);

        System.out.println("\n(x,n)=(" + x + "," + n + ")"+" Public Key");
        System.out.println("\n(y,n)=(" + y + "," + n + ")" +" Private Key\n");
    }

    void cipher(char[] T, int k, int n) // k = e or d
    {
        for (int i=0; i < T.length; i++)
        {
            T[i] = (char)pow(T[i], k, n);
        }
        System.out.println("C: " + String.valueOf(T));
    }

    void input()
    {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter T:");
        T = scanner.next();
        scanner.close();
    }

    void output()
    {
        System.out.println("\nT: " + T);
        char[] M = T.toCharArray();
        //System.out.println("Before encryption M: " + String.valueOf(M));
        cipher(M, x, n); // M^x % n
        //System.out.println("After encryption M: " + String.valueOf(M));
        cipher(M, y, n); // C^y % n
    }
    
    public static void main(String[] args)
    {
        RSA r = new RSA();
        r.rsa();
        r.input();
        r.output();
    }
}


