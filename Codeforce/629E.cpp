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

int t;
vi p,d,tin,tout;
vector<vector<int> > g;

void dfs(int v, int par=-1,int deg=0){
	p[v] = par;
	d[v] = deg;
	tin[v] = t++;
	for(auto u : g[v]){
		if(u==par) continue;
		dfs(u,v,deg+1);
	}
	tout[v] = t++;
}

bool isAnc(int v, int u){
	return tin[v] <= tin[u] && tout[v] >= tout[u];
}

int main(){
	c_p_c();
	int n,m;
	cin >> n >> m;
	p = d = tin = tout= vi(n);
	g = vector<vi>(n);
	t=0;
	fo(i,n-1){
		int f,s; cin >> f >> s;
		--f,--s;
		g[f].pb(s);
		g[s].pb(f);
	}

	dfs(0);
	fo(i,m){
		int k; cin >> k;
		vi a(k);
		fo(i,k) cin >> a[i], --a[i];
		int u = a[0];

		for(auto it : a) if(d[it] > d[u]) u = it;

		for (auto &it : a) {
			if (it == u) continue;
			if (p[it] != -1) it = p[it];
		}

		bool ok = true;
		for(auto it: a) ok &= isAnc(it,u);
		if(ok) cout << "YES\n";
		else cout << "NO\n";
	}

	return 0;
}