#include<bits/stdc++.h>
using namespace std;

int findMinIndex(bool visited[] , int weights[]){
	int min_Index, min = INT_MAX;
	for(int i=0;i<5;i++){
		if(!visited[i] && weights[i] < min)
			min = weights[i] , min_Index = i;
	}

	return min_Index;
}

void prims(int graph[5][5]){
	bool *visited = new bool[5];
	int *weights = new int[5];
	int *parent = new int[5];

	for(int i=0;i<5;i++){
		visited[i] = false;
		weights[i] = INT_MAX;
		
	}
	parent[0] = -1;
	weights[0] = 0;

	for(int i=0;i<4;i++){
		int u = findMinIndex(visited, weights);
		visited[u] = true;

		for(int v= 0; v < 5; v++){
			if(!visited[v] && graph[v][u]){
				if(weights[v] > graph[v][u]){
					weights[v] = graph[v][u];
					parent[v] = u; 
				}
			}
		}
	}

	for(int i=0; i<5; i++){
		cout << i << " " << parent[i] << " " << weights[i] << endl;
	}
}

int main(){
	int graph[5][5] = { {0,4,0,0,0}, {4,0,2,6,0}, {0,2,0,3,9}, {0,6,3,0,6}, {0,0,9,6,0}};
	prims(graph);
}