#include <bits/stdc++.h>
using namespace std;

#define V 6

//function to fin vertex with min value
int minKey(int key[], bool mst_set[]){
	int min = INT_MAX, min_index;

	for (int v = 0; v < V; v++){
		if (mst_set[v] == false && key[v] < min){
			min = key[v], min_index = v;
        }
    }
	return min_index;
}

//function to print MST
void printMST(int parent[], int graph[V][V])
{
	cout << "Edge  :  Weight\n";
	for (int i = 1; i < V; i++){
		cout << parent[i] << " - " << i << "  :  "<< graph[i][parent[i]] << " \n";
    }	
}

//find mst using prim's algorithm
void primMST(int graph[V][V]){
	int parent[V];
	int key[V];
	bool mst_set[V];

	for (int i = 0; i < V; i++){
		key[i] = INT_MAX;
        mst_set[i] = false;
    }
	key[0] = 0;
	parent[0] = -1;

	for (int c = 0; c < V - 1; c++) {
		int u = minKey(key, mst_set);
		mst_set[u] = true;
		for (int v = 0; v < V; v++){
			if (graph[u][v] && mst_set[v] == false&& graph[u][v] < key[v]){
				parent[v] = u, key[v] = graph[u][v];
            }
        }
	}
	printMST(parent, graph);
}


int main()
{
	int G[V][V] = { 
        {0, 3, 0, 0, 0, 1},
        {3, 0, 2, 1, 10, 0},
        {0, 2, 0, 3, 0, 5},
        {0, 1, 3, 0, 5, 0},
        {0, 10, 0, 5, 0, 4},
        {1, 0, 5, 0, 4, 0} 
        };

	
	primMST(G);

	return 0;
}

