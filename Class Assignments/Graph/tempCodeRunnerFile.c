#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#define V 4
#define MAX 100
void init(int arr[][V])
{
    int i, j;
    for(i = 0; i<V; i++)
    {
        for(j = 0; j<V; j++)
        {
            arr[i][j] = 0;
        }
    }
}

void addEdge(int arr[][V], int i, int j)
{
    arr[i][j] = 1;
    arr[j][i] = 1;
}

void printAdjMatrix(int arr[][V])
{
    int i, j;
    char node = 'A';
    for(i = 0; i<V; i++)
    {
        printf("%C: ", node);
        node++;
        for(j = 0; j<V; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}

void bfs(int adj[MAX][MAX], int v, int s){
    int q[MAX], front = 0, rear = 0;
    bool visited[MAX] = {false};

    visited[s] = true;
    q[rear++] = s;

    while(front < rear){
        //dequeue
        int current = q[front++];
        printf("%d", current);

        for(int i = 0; i<v; i++){
            if(adj[current][i] == 1 && !visited[i]){
                visited[i] = true;
                q[rear++] = i;
            }
        }
    } 
}

int main()
{
    int adjMatrix[V][V];

    init(adjMatrix);
    addEdge(adjMatrix,0,1);
    addEdge(adjMatrix,0,2);
    addEdge(adjMatrix,1,2);
    addEdge(adjMatrix,2,0);
    addEdge(adjMatrix,2,3);

    printAdjMatrix(adjMatrix);
    printf("\n");

    bfs(adjMatrix,V,3);

}