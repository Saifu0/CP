#include<bits/stdc++.h>
using namespace std;

const int N = 12345;

int parent[N];
vector<int> g[N];

int find(int x){
	if(parent[x] == -1) return x;
	return find(parent[x]);
}

void Union(int x, int y){
	int n1 = find(x);
	int n2 = find(y);

	if(n1 != n2) parent[n1] = n2;
}

bool isCycle(int n, int v){
	for(int i=0;i<n;i++){
		for(int j=0;j<g[i].size();j++){
			int x = find(i);
			int y = find(g[i][j]);

			if(x==y) return 1;

			Union(x,y);
		}
	}	
	return 0;
}

int main(){
	memset(parent,-1,sizeof(parent));
	int n,e;
	cin >> n >> e;
	for(int i=0;i<e;i++){
		int f,s;
		cin >> f >> s;
		g[f].push_back(s);
	}

	if(isCycle(n,1)) cout << "Graph contain cycle" << endl;
	else cout << "Graph not contain cycle" << endl;
}
