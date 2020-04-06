#include<bits/stdc++.h>
using namespace std;

int matrix[1001][1001];

void DFS(int V,int s, bool* visited){

	visited[s] = true;

	for(int i=0; i<V; i++){
		if(matrix[i][s] == 1 && !visited[i])
			DFS(V, i, visited);
	}
}

int main(){
	int v,e;
	cin >> v >> e;

	for(int i=0;i<1001;i++){
		for(int j=0;j<1001;j++){
			matrix[i][j] = 0;
		}
	}

	for(int i=0;i<e;i++){
		int s,d;
		cin >> s >> d;
		matrix[s][d] = 1;
		matrix[d][s] = 1;
	}

	bool* visited = new bool[v];
	for(int i=0;i<v;i++){
		visited[i] = false;
	}

	DFS(v,0,visited);

	for(int i=0;i<v;i++){
		if(!visited[i]){
			cout << "false" << endl;
			return 0;
		}
	}

	cout << "true" << endl;


	
} 