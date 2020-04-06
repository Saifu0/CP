#include<bits/stdc++.h>
using namespace std;

class Graph{
	int V;
	int matrix[10][10];
public:
	Graph(int V);
	void addEdge(int s,int v);
	void BFS(int s);
};

Graph::Graph(int V){
	this->V = V;
	for(int i=0;i<10;i++){
		for(int j=0;j<10;j++){
			matrix[i][j] = 0;
		}
	}
}

void Graph::addEdge(int i,int j){
	matrix[i][j] = 1;
	matrix[j][i] = 1;
}

void Graph::BFS(int s){
	bool *visited = new bool[V];
	for(int i=0;i<V;i++)
		visited[i] = false;

	queue<int> q;
	q.push(s);
	visited[s] = true;

	while(!q.empty()){
		int temp = q.front();
		cout << temp << " ";
		q.pop();

		for(int i=0; i<V;i++){
			if(matrix[temp][i] == 1 && !visited[i]){
				visited[i] = true;
				q.push(i);
			}
		}
	}
}

int main(){
	Graph g(10);
	g.addEdge(0, 1); 
    g.addEdge(0, 2); 
    g.addEdge(1, 2); 
    g.addEdge(2, 0); 
    g.addEdge(2, 3); 
    g.addEdge(3, 3); 

    cout << "Following is Breadth First Traversal "
         << "(starting from vertex 2) \n"; 
    g.BFS(2);

}