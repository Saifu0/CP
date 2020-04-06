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
	int q;
	cin >> q;
	while(q--){
		int n,m;
		cin >> n >> m;
		vector<int>* edges = new vector<int>[n];

		int* p = new int[n];
		int* q = new int[n];

		for(int i=0;i<n;i++){
			cin >> p[i];
		}

		for(int i=0;i<n;i++){
			cin >> q[i];
		}


		for(int i=0;i<m;i++){
			int f,s;
			cin >> f >> s;
			edges[f-1].push_back(s-1);
			edges[s-1].push_back(f-1);
		}

		unordered_set<unordered_set<int>*>* comp = getComponents(edges,n);
		unordered_set<unordered_set<int>*>::iterator it1 = comp->begin();
		bool flag = true;
		while(it1 != comp->end()){
			unordered_set<int>* com = *it1;
			unordered_set<int>::iterator it2 = com->begin();
			
			map<int,int> m;
			for(;it2!=com->end();it2++){
				m[p[*it2]]++;
				m[q[*it2]]++;
			}

			for(it2=com->begin();it2!=com->end();it2++){
				if(m[p[*it2]] == 1 || m[q[*it2]] == 1){
					flag = false;
					break;
				}
			}
			it1++;
			delete com;
		}

		if(flag == false) cout << "NO" << endl;
		else cout << "YES" << endl;

		delete comp;
		delete[] edges;
	}
	
}