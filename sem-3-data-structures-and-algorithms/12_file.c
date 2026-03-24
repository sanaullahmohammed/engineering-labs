/*
Given a File of N employee records with a set K of Keys (4-digit) which uniquely determine
the records in le F. Assume that le F is maintained in memory by a Hash Table (HT) of m
memory locations with L as the set of memory addresses (2-digit) of locations in HT. Let the
keys in K and addresses in L are Integers. Design and develop a Program in C that uses Hash
function H: K ®L as H(K)=K mod m (remainder method), and implement hashing technique
to map a given key K to the address space L. Resolve the collision (if any) using linear probing.
*/

#include <stdio.h>
#include <stdlib.h>
#define m 7
int ht[m];
/*
1. Store key in HT at the index hk
2. if HT at hk is not avialable store next free location after hk
3. | 0 | 1 | 2 | 3 | 4 |, h = 2, h+5 % 5 = 2 wraps around after m
*/
void store(int key, int hk)
{
    // not sure about pos and flag as they aren't used
    int pos = -1;
    int flag;
    int n = hk;
    for (int i = 0; i < m; i++)
    {
        if (ht[n] == -1)
        {
            if (n != hk) printf(" Collision.\n");
            ht[n] = key;
            return;
        }
        n = ++n % m;
    }
    printf(" Overflow?\n");
}
/*
1. Display the HT
*/
void display()
{
    printf("Hash Table:\n");
    for(int i = 0; i < m; i++)
    {
        printf("%d\t%d\n", i, ht[i]);
    }
}

void init()
{
    for(int i = 0; i < m; i++)
    {
        ht[i] = -1;
    }
}
/*
1. Initialize HT with empty values (say -1)
2. Generate 4 digits keys
3. Map 4 digit key to 2 digit hash key
4. Store the key at HT[hk]
*/
int main()
{
    FILE *fp;
    fp = fopen("12.txt", "r");
    int key;
    int hk;
    int n;
    init();

    printf("Enter number of records: ", &n);
    scanf("%d", &n);

    for (int i=0; i < n; i++)
    {
        fscanf(fp, "%d", &key);
        hk = key % m;
        printf("store n=%d, key=%d, hk=%d\n", i, key, hk);
        store(key, hk);
    }
    display();
}

/*
FILE: 12.txt
1000
1005
1005
1010
1015
1020

Enter number of records: 5
*/