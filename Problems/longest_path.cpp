#include<bits/stdc++.h>
using namespace std;

vector<vector<int> > v(10001);
int vis[10001];

int maxD, maxNode;

void dfs(int node, int d){
	vis[node] = 1;
	if(d > maxD) maxD = d, maxNode = node;
	
	for(int child : v[node])
	if(vis[child] == 0)
	dfs(child, d+1);
	
}

int main(){
		int n,a ,b;
		cin >> n;
		for(int i=0;i<n-1;i++){
			 cin >> a >> b;
			 v[a].push_back(b);
			  v[b].push_back(a);
		  }

		maxD = -1;
		dfs(1,0);
		
		maxD = -1;
		for(int i=0;i<=n;i++) vis[i] = 0;
		dfs(maxNode, 0);
		
		cout << maxD << endl;
}
