#include<bits/stdc++.h>
using namespace std;

int matrix[1001][1001];

void addEdge(int start, int end){
	matrix[start][end] = end;
	matrix[end][start] = start;
}

bool BFS(int V,int s, int v){

	if(s == v) return true;

	bool* visited = new bool[V];
	for(int i=0;i<V;i++)
		visited[i] = false;

	queue<int> q;
	q.push(s);

	visited[s] = true;

	while(!q.empty()){
		s = q.front();
		q.pop();

		for(int i=0;i<1001;i++){
			if( matrix[s][i] == v) return true;
		

			if( !visited[matrix[s][i]]){
				visited[matrix[s][i]] = true;
				q.push(matrix[s][i]);
			}
		}	
	}
	return false;
}

int main(){
	int V,E;
	cin >> V >> E;

	for(int i=0;i<1001;i++){
		for(int j=0;j<1001;j++){
			matrix[i][j] = 0;
		}
	}

	for(int i=0;i<E;i++){
		int start, end;
		cin >> start >> end;
		addEdge(start, end);
	}

	int v1, v2;
	cin >> v1 >> v2;

	

	bool res = BFS(V, v1, v2);

	if(res) cout << "true" << endl;
	else cout << "false" << endl;


}