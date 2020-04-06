#include <bits/stdc++.h>
using namespace std;

class Graph {
      
    int  V;
    int matrix[1001][1001];
    
public:
    Graph(int V);
    void addEdge(int start, int end);
    void BFS(int s, bool * visited);
    
    
};

Graph::Graph(int V){
    this->V = V;
    for(int i=0;i<1001;i++){
        for(int j=0;j<1001;j++){
            matrix[i][j] = 0;
        }
    }
}

void Graph::addEdge(int start, int end){
    matrix[start][end] = 1;
    matrix[end][start] = 1;
}

void Graph::BFS(int s, bool* visited){
    
    
    queue<int> q;
    q.push(s);
    visited[s] =  true;
    
    while(!q.empty()){
        int temp = q.front();
        cout << temp << " ";
        q.pop();
        
        for(int i=0;i<V;i++){
            if(matrix[temp][i] == 1 && !visited[i]){
                visited[i] = true;
                q.push(i);
            }
        } 
    }
}

int main() {
    int V, E;
    cin >> V >> E;
    Graph g(V);
    
    for(int i=0;i<E;i++){
        int start, end;
        cin >> start >> end;
        g.addEdge(start, end);
    }
    bool *visited = new bool[V];
    for(int i=0;i<V;i++)
        visited[i] = false;
    
    for(int i=0;i<V;i++){
        if(!visited[i]){
            g.BFS(i,visited);
        }
    }

  

  return 0;
}
 