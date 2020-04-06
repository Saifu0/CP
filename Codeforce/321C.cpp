#include<bits/stdc++.h>
using namespace std;

const int mx = 100500;

vector<int> g[mx];
int n,m;
int c[mx];
int s;

void dfs(int v, int anc, int h){
	if(c[v]) ++h;
	else h=0;
	if(h==m+1) return;
	bool lf = true;
	for(auto i : g[v]){
		if(i != anc){
			lf = false;
			dfs(i,v,h);
		}
	}
	if(lf) ++s;
}

int main(){
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++) scanf("%d",&c[i]);
	for(int i=0;i<n-1;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		g[--u].push_back(--v);
		g[v].push_back(u);
	}
	dfs(0,-1,0);
	cout << s << endl;
}
