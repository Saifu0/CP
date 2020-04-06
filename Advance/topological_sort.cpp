#include<bits/stdc++.h>
using namespace std;

const int N = 12345;
vector<int> g[N];
stack<int> s;
bool vis[N];

void solve(int v){
	vis[v] = true;
	for(int i=0;i<g[v].size();i++){
		if(!vis[g[v][i]]) solve(g[v][i]);
	}
	s.push(v);
}

int main(){
	int n,e;
	cin >> n >> e;
	for(int i=0;i<e;i++){
		int f,s;
		cin >> f >> s;
		g[f].push_back(s);
	}

	memset(vis,false,sizeof(vis));
	
	for(int i=0;i<n;i++)
		if(vis[i] == false) solve(i);

	while(!s.empty()){
		cout << s.top() << endl;
		s.pop();
	}
}
