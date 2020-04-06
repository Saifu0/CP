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

const int mxn = 2e6+100;
int n;
vi g[mxn];
int c[mxn];
int ans = 0;
bool vis[mxn];

void dfs(int v){
	if(vis[v]) return;
	if(c[v]) return;

	fo(i,sz(g[v])){
		int u = g[v][i];
		if(!vis[u]){
			ans++;
			dfs(u);
		}
	}
}

int main(){
	c_p_c();
	cin >> n;
	fo(i,n-1){
		int f, s;
		cin >> f >> s;
		g[f].pb(s);
		g[s].pb(f);
	}
	Fo(i,1,n+1) cin >> c[i];

	int cnt = 0;
	Fo(i,1,n+1){
		vis[n+1] = {false};
		ans = 1;
		if(!c[i]) dfs(i);
		cnt = max(cnt,ans);
	}
	

	cout << cnt << endl;

	return 0;
}