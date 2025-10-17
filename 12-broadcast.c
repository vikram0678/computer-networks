/*
------------------------------------------------------------
    AIM: Write a program to implement Broadcast Tree 
         by taking subnet of hosts.
------------------------------------------------------------
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX 20

// Function to create and display broadcast tree
void createBroadcastTree(int hosts[MAX][MAX], int n) {
    printf("\nAdjacency Matrix (Subnet Representation):\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", hosts[i][j]);
        }
        printf("\n");
    }

    printf("\nBroadcast Tree Traversal (using BFS):\n");
    int visited[MAX] = {0}, queue[MAX], front = 0, rear = 0;

    int start;
    printf("Enter the starting node (0 to %d): ", n - 1);
    scanf("%d", &start);

    visited[start] = 1;
    queue[rear++] = start;

    while (front < rear) {
        int node = queue[front++];
        printf("Node %d is broadcasting...\n", node);

        for (int i = 0; i < n; i++) {
            if (hosts[node][i] == 1 && !visited[i]) {
                visited[i] = 1;
                queue[rear++] = i;
            }
        }
    }
}

int main() {
    int hosts[MAX][MAX], n;

    printf("Enter number of hosts (nodes): ");
    scanf("%d", &n);

    printf("Enter adjacency matrix (1 if connected, 0 if not):\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &hosts[i][j]);
        }
    }

    createBroadcastTree(hosts, n);

    printf("\nBroadcast completed successfully!\n");
    return 0;
}

/*
------------------------------------------------------------
OUTPUT (Example):

Enter number of hosts (nodes): 4
Enter adjacency matrix (1 if connected, 0 if not):
0 1 1 0
1 0 0 1
1 0 0 1
0 1 1 0

Adjacency Matrix (Subnet Representation):
0 1 1 0
1 0 0 1
1 0 0 1
0 1 1 0

Enter the starting node (0 to 3): 0
Broadcast Tree Traversal (using BFS):
Node 0 is broadcasting...
Node 1 is broadcasting...
Node 2 is broadcasting...
Node 3 is broadcasting...

Broadcast completed successfully!
------------------------------------------------------------
*/

