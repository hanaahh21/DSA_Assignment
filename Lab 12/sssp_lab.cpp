#include <iostream>
#include <limits.h>
using namespace std;
#define V 6
void dijkstra(int graph[V][V], int src);
int min_distance(int dist[], int visited[]);


//function to find the minimum distance of vertex and returns its index
int min_distance(int dist[], bool visited[]){
    int minDist = INT_MAX;
    int minIndex;

    for(int v = 0; v<V; v++){
        if(!visited[v] && dist[v] <= minDist){
            minDist = dist[v];
            minIndex = v;
        }
    }
    return minIndex;
}

//Implement dijkstras algorithm
void dijkstra(int graph[V][V], int src){
    int dist[V];
    bool visited[V];

    for(int i = 0; i<V ; i++){
        dist[i] = INT_MAX;
        visited[i] = false;
    }

    dist[src] = 0;

    for(int count = 0; count <V-1; count++){
        int u = min_distance(dist, visited);
        visited[u]= true;

        for(int v =0; v< V; v++){
            if(!visited[v] && graph[u][v] && dist[u] != INT_MAX && dist[u]+graph[u][v] < dist[v]){
                dist[v] = dist[u] + graph[u][v];
            }
        }

    }

    float sum = 0;
    for(int k = 0; k<V; k++){
        cout<< "Time duration of node " << k << " - " << dist[k] <<endl;
        sum += dist[k];
    }

    //to find the average distance from each source node (optional)
    float average = sum/5;
    cout<< "Average time duration from source "<< src << " is "<< average << endl;
}


int main(){
    //initialize adjacency matrix of graph
    int graph[6][6] = {
        {0, 10, 0, 0, 15, 5},
        {10, 0, 10, 30, 0, 0},
        {0, 10, 0, 12, 5, 0},
        {0, 30, 12, 0, 0, 20},
        {15, 0, 5, 0, 0, 0},
        {5, 0, 0, 20, 0, 0}
    };

    for(int s = 0 ; s < 6 ; s++){
        cout << "Source City: "<< s<< endl;
        dijkstra(graph, s);
        cout << endl;
    }
    return 0;
}
