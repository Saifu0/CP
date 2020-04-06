#include<bits/stdc++.h>
using namespace std;

int matrix[1001][1001];

void DFS(int V, int s, bool* visited){
	cout << s << " ";
	visited[s] = true;

	for(int i=0;i<1001;i++){
		if(!visited[matrix[s][i]]){
			DFS(V,matrix[s][i],visited);
		}
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
		matrix[s][d] = s;
		matrix[d][s] = d;
	}

	bool* visited = new bool[v];
	for(int i=0;i<v;i++){
		visited[i] = false;
	}

	for(int i=0;i<v;i++){
		if(!visited[i]){
			
			DFS(v,i,visited);
			
			cout << "\n";
		}
		
	}
	return 0;
}