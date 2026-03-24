/*
Design, Develop and Implement a Program in C for the following operations on Graph(G) of
Cities
a. Create a Graph of N cities using Adjacency Matrix.
b. Print all the nodes reachable from a given starting node in a digraph using DFS/BFS
method
*/

#include <stdio.h>
int a[10][10];
int visited[10];
int n;
/*
1. explore the root vertex i
2. from i explore vertices (j) and process each vertex recursively
*/
void dfs(int i)
{
    visited[i] = 1;
    printf("%d ", i);
    for(int j=0; j < n; j++)
    {
        if(a[i][j] && !visited[j]) dfs(j);
    }
}
/*

1

Chapter 11. Graph 15CSL38
1. count vertices visited and same as number of cities then G is connected
*/
void connected()
{
    int count = 0;
    for (int i=0; i < n; i++)
    {
        if(visited[i]) count++;
    }
    count == n ? printf("Connected.") : printf("NOT Connected.");
}
/*
1. Read number of cities
2. Read the graph as adjacency matrix
*/
void init()
{
    printf("Enter number of cities: ");
    scanf("%d", &n);
    printf("Enter graph a[][]:\n");
    for(int i=0; i < n; i++)
    {
        visited[i] = 0;
        for(int j=0; j < n; j++)
        {
        scanf("%d", &a[i][j]);
        }
    }
}


int main()
{
    init();
    printf("DFS ");
    dfs(0);
    connected();
}

/*
Test cases
1) Test
A A
/ \ / \
B C B C
/ / \ / / \
D E F D E F
BFS: A, B, C, D, E, F DFS: A, B, D, C, E, F
n = 6
0 1 1 0 0 0
0 0 0 1 0 0
0 0 0 0 1 1
0 1 0 0 0 0
0 0 1 0 0 0
0 0 1 0 0 0
DFS 0 1 3 2 4 5
Connected
2) Test 2
Repeat when F is not connected i.e (C,F) = 0
n = 6
0 1 1 0 0 0
0 0 0 1 0 0
0 0 0 0 1 0
0 1 0 0 0 0
0 0 1 0 0 0
0 0 1 0 0 0
DFS 0 1 3 2 4 5
NOT connected
3) Test 3
0-------3
| \
| 2
| / \
|/ \
1 4
0 1 2 3 4
0 1 1 1 0
1 0 1 0 0
1 1 0 0 4
1 0 0 0 0
0 0 2 0 0
*/