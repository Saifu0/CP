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
	int t;
	cin >> t;
	while(t--){
		int n,e;
		cin >> n >> e;
		vector<int>* edges = new vector<int>[n];
		for(int i=0;i<e;i++){
			int f,s;
			cin >> f >> s;
			edges[f-1].push_back(s-1);
			edges[s-1].push_back(f-1);
		}
		int value[n];
		for(int i=0;i<n;i++){
			cin >> value[i];
		}
		unordered_set<unordered_set<int>*>* comp = getComponents(edges,n);
		unordered_set<unordered_set<int>*>::iterator it1 = comp->begin();
		int max = INT_MIN;
		while(it1 != comp->end()){
			int temp = 0;
			unordered_set<int>* com = *it1;
			unordered_set<int>::iterator it2 = com->begin();
			while(it2 != com->end()){
				temp += value[*it2];
				it2++;
			}	
			max = temp > max ? temp : max;
			delete com;
			it1++;	
		}
		cout << max << endl;
	}
}