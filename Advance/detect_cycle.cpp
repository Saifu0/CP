#include<bits/stdc++.h>
using namespace std;

const int N = 12345;
bool vis[N], rec[N];
vector<int> g[N];

bool isCycle(int n,int v){
	if(!vis[v]){
		vis[v] = true;
		rec[v] = true;

		for(int i=0;i<g[v].size();i++){
			if(!vis[g[v][i]] && isCycle(n,g[v][i])) return true;
			else if(rec[g[v][i]]) return true;
		}
	}
	rec[v] = false;
	return false;	
}

int main(){
	int n,e;
	cin >> n >> e;
	for(int i=0;i<e;i++){
		int f,s;
		cin >> f >> s;
		g[f].push_back(s);
	}

	for(int i=0;i<n;i++) vis[i] = false, rec[i] = false;

	if(isCycle(n,1)) cout << "Cycle exists" << endl;
	else cout << "Cycle doesnot exist" << endl;
}
