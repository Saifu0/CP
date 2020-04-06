#include<bits/stdc++.h>
using namespace std;

#define deb(x) cout << #x << " " << x << endl;
#define fo(i,n) for(int i=0;i<n;i++)
#define Fo(i,k,n) for(int i=k;i<n;i++)
#define vi vector<int>
#define ii pair<int,int>
#define vii vector<ii>
#define ll long long
#define pb push_back
#define endl "\n"
#define mp map<int,int>
#define F first
#define S second
#define sz(v) (int)v.size()
#define mod 1000000007

void c_p_c()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}

int n,e;
const mxn = 123456;
g[mxn][mxn];
bool vis[mxn] ={false};
int dist[mxn] = {INT_MAX};
int parent[mxn];

void solve(){
	dist[1] = 0;
	parent[1] = -1;

	for(int i=1;i<n;i++){
		int u = minDis();
		vis[u] = true;

		for(int v=1;v<=n;v++){
			if(!vis[v] && g[u][v] && dist[j] != )
		}
	}
}



int main(){
	c_p_c();

	
	cin >> n >> e; 
	fo(i,e){
		int f,s,wt;
		cin >> f >> s >> wtw;
		g[f][s] = wt;
		g[s][f] = wt;
	}

	solve();

	return 0;
}