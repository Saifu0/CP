#include<bits/stdc++.h>
using namespace std;

void dfs(vector<int>* edges, int start, unordered_set<int> &visited, stack<int>& finishedVertices){
	visited.insert(start);
	for(int i=0;i<edges[start].size();i++){
		int adj = edges[start][i];
		if(visited.count(adj) == 0){
			dfs(edges, adj, visited, finishedVertices);
		}
	}
	finishedVertices.push(start);
}

void dfs2(vector<int>* edges, int start, unordered_set<int>* component, unordered_set<int> & visited){
	visited.insert(start);
	component->insert(start);
	for(int i=0;i<edges[start].size();i++){
		int adj = edges[start][i];
		if(visited.count(adj) == 0){
			dfs2(edges, adj, component, visited);
		}
	}
}


unordered_set<unordered_set<int>*>* getSCC(vector<int>* edges, vector<int>* edgesT, int n){
	unordered_set<int> visited;
	stack<int> finishedVertices;

	for(int i=0;i<n;i++){
		if(visited.count(i) == 0){
			dfs(edges, i, visited, finishedVertices);
		}
	}

	unordered_set<unordered_set<int>*>* output = new unordered_set<unordered_set<int>*>();
	visited.clear();
	while(finishedVertices.size() != 0){
		int element = finishedVertices.top();
		finishedVertices.pop();
		if(visited.count(element) != 0){
			continue;
		}
		unordered_set<int>* component = new unordered_set<int>();
		dfs2(edgesT,element, component, visited);
		output->insert(component);
	}
	return output;

}

int main(){
	int n,e;
	cin >> n;
	while(n!=0){
		cin >> e;
		vector<int> * edges = new vector<int>[n];
		vector<int> *edgesT = new vector<int>[n];
		for(int i=0;i<e;i++){
			int f,s;
			cin >> f >> s;
			edges[f-1].push_back(s-1);
			edgesT[s-1].push_back(j-1);
		}
		unordered_set<unordered_set<int>*>* components = getSCC(edges, edgesT, n);
		cin >> n;
	}
	return 0;
}