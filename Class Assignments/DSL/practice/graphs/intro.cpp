#include <iostream>
#include<climits>
using namespace std;

#define V 4
#define MAX 100

void init(int adj[][V]){
    for(int i = 0; i<V; i++){
        for(int j = 0; j<V; j++){
            adj[i][j] = 0;
        }
    }
}

void addEdge(int adj[][V], int i, int j, int weight){
    adj[i][j] = weight;
    adj[j][i] = weight;
}

void printAdjMatrix(int adj[][V]){
    char label = 65;
    for(int i = 0; i<V; i++){

        cout << label << ": ";

        for(int j = 0; j<V; j++){
            cout << adj[i][j] << " ";
        }
        cout << "\n";
        label++;
    }
}

    void bfs(int adj[][V], int v, int s){
        int q[MAX];
        int front = 0;
        int rear = 0;
        bool visited[MAX] = {false};

        //enqueue
        visited[s] = true;
        q[rear++] = s;

        //dequeue
        while(front < rear){
            int current = q[front++];
            cout << current << " ";

            //visiting neighbors of current node
            for(int i = 0; i<V; i++){
                if(adj[current][i] == 1 && !visited[i]) //found the neighbor
                {
                    visited[i] = true;
                    q[rear++] = i;
                }
            }
        }
    }


int minKey(int key[], bool mstSet[]){
    int min = INT_MAX, minIndex;

    for(int v = 0; v<V; v++){
        if(!mstSet[v] && key[v] < min){
            min = key[v];
            minIndex = v;
        }
    }
    return minIndex;
}

void printMST(int parent[], int graph[][V]){
    cout << "Edge \tWeight\n";
    for(int i = 1; i<V; i++){
        cout << parent[i] << " - " << i << "\t" << graph[i][parent[i]] << " \n";
    }
}

void prims(int graph[][V]){
    int parent[V];
    int key[V];
    bool mstSet[V];

    for(int i = 0; i<V; i++){
        key[i] = INT_MAX;
        mstSet[i] = false;
    }

    key[0] = 0;
    parent[0] = -1;

    for(int count = 0; count < V-1; count++){
        int u = minKey(key, mstSet);
        mstSet[u] = true;

        for(int v = 0; v<V; v++){
            if(graph[u][v] && !mstSet[v] && graph[u][v] < key[v]){
                parent[v] =u;
                key[v] = graph[u][v];   
            }
        }
    }
    printMST(parent,graph);
}

void dijkstra(int graph[][V],int source){
    int dist[V];
    bool visited[V];

    for(int i = 0; i<V; i++){
        dist[i] = INT_MAX;
        visited[i] = false;
    }

    dist[source] = 0;

    for(int count = 0; count< V-1; count++){
        int u = minKey(dist, visited);
        visited[u] = true;

        for(int v = 0; v<V; v++){
            if(!visited[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v]){
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }
    cout << "vertex \t\t Distance from Source" << endl;
    for(int i = 0; i<V; i++){
        cout << i << "\t\t" << dist[i] << endl;
    }
}



int main(){

    int adj[V][V];
    init(adj);

    addEdge(adj, 0, 1, 10);
    addEdge(adj, 0, 2, 6);
    addEdge(adj, 1, 2, 5);
    addEdge(adj, 2, 3, 4);

    cout << "\nMinimum Spanning Tree (Prim's Algorithm):\n";
    prims(adj);


    

}