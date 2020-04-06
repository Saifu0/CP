#include<bits/stdc++.h>
using namespace std;

bool DFS(int** edges, bool* visited, int V, int sv, int ev, vector<int>& v)
{
    if(sv == ev)
    {
        v.push_back(sv);
        return true;
    }
    visited[sv] = true;
    for(int i = 0; i < V; i++)
    {
        if(i == sv)
        {
            continue;
        }
        if(edges[sv][i] == 1 && i == ev)
        {
            v.push_back(i);
            return true;
        }
        if(edges[sv][i] == 1 && !visited[i])
        {
            bool ans = DFS(edges, visited, V, i, ev, v);
            if(ans)
            {
                v.push_back(i);
                return true;
            }
        }
    }
    return false;
}

int main() {
    int V, E;
    cin >> V >> E;
    int** edges = new int*[V];
    for(int i = 0; i < V; i++)
    {
        edges[i] = new int[V];
        for(int j = 0; j < V; j++)
        {
            edges[i][j] = 0;
        }
    }
    for(int i = 0; i < E; i++)
    {
        int f, s;
        cin >> f >> s;
        edges[f][s] = 1;
        edges[s][f] = 1;
    }
    int a, b;
    cin >> a >> b;
    bool* visited = new bool[V];
    for(int i = 0; i < V; i++)
    {
        visited[i] = false;
    }
    vector<int> v;
    if(DFS(edges, visited, V, a, b, v))
    {
        for(int i = 0; i < v.size(); i++)
        {
            cout << v[i] << " ";
        }
        cout << a;
    }
    delete []visited;
    for(int i = 0; i < V; i++)
    {
        delete []edges[i];
    }
    delete []edges;
    return 0;
}