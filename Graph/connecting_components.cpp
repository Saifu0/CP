#include<bits/stdc++.h>
using namespace std;

void dfs(vector<int>* edges, int start, bool* visited, unordered_set<int>* comp){
	visited[start] = true;
	comp->insert(start);

	for(int i=0;i<edges[start].size();i++){
		int next = edges[start][i];
		if(!visited[next])
			dfs(edges, next, visited, comp);
	}
}

unordered_set<unordered_set<int>*>* getComponents(vector<int>* edges, int n){
	bool* visited = new bool[n];
	for(int i=0;i<n;i++)
		visited[i] = false;

	unordered_set<unordered_set<int>*>* output = new unordered_set<unordered_set<int>*>();

	for(int i=0;i<n;i++){
		if(!visited[i]){
			unordered_set<int> * comp = new unordered_set<int>();
			dfs(edges, i, visited, comp);
			output->insert(comp);
		}
	}
	return output;
}

int main(){
	int n,m;
	cin >> n >> m;
	vector<int>* edges = new vector<int>[n];

	for(int i=0;i<m;i++){
		int f,s;
		cin >> f >> s;
		edges[f-1].push_back(s-1);
		edges[s-1].push_back(f-1);
	}
	unordered_set<unordered_set<int>*>* comp = getComponents(edges,n);
	unordered_set<unordered_set<int>*>::iterator it1 = comp->begin();

	while(it1 != comp->end()){
		unordered_set<int>* com = *it1;
		unordered_set<int>::iterator it2 = com->begin();
		while(it2 != com->end()){
			cout << *it2 + 1 << " ";
			it2++;
		}	
		cout << "\n";
		delete com;
		it1++;
	}
	delete comp;
	delete[] edges;
}