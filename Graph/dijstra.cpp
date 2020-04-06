#include<bits/stdc++.h>
using namespace std;

int findminVertex(bool* visited, int* dist, int n){
	int minVertex = -1;
	for(int i=0;i<n;i++){
		if(!visited[i] && (minVertex == -1 || dist[i] < dist[minVertex])){
			minVertex = i;
		}
	}
	return minVertex;
}

void dijstra(int**edges, int n){
	bool* visited = new bool[n];
	int* dist = new int[n];
	dist[0] = 0;
	for(int i=1;i<n;i++){
		dist[i] = INT_MAX;
	}

	for(int j=0;j<n-1;j++){
		int u = findminVertex(visited, dist, n);
		visited[u] = true;

		for(int i=0;i<n;i++){
			if(edges[u][i] && !visited[i]){
				int curr = dist[u] + edges[u][i];
				if(dist[i] > curr){
					 dist[i] = curr;
				}
			}
		}
	}

	for(int i=0;i<n;i++){
		cout << i << " " << dist[i] << " " << endl;
	}
	delete[] visited;
	delete[] dist;
}

int main(){
	int n,e;
	cin >> n >> e;
	int**edges = new int*[n];
	for(int i=0;i<n;i++){
		edges[i] = new int[n];
		for(int j=0;j<n;j++){
			edges[i][j] = 0;
		}
	}
	for(int i=0;i<e;i++){
		int f, s, weight;
		cin >> f >> s >> weight;
		edges[f][s] = weight;
		edges[s][f] = weight;
	}

	dijstra(edges,n);
}