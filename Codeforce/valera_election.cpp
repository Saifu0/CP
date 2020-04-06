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

const int mxn = 300000+300;
vi w(mxn,0),d(mxn,0);
vi g[mxn];
int n;

void dfs(int v, int p=-1){
	d[v] = w[v];
	fo(i,sz(g[v])){
		int u = g[v][i];
		if(u==p) continue;
		dfs(u,v);
		d[v] += d[u];
	}
}

int main(){
	c_p_c();
	cin >> n;
	fo(i,n-1){
		int f,s,t; cin >> f >> s >> t;
		--f,--s;
		g[f].pb(s);
		g[s].pb(f);
		if(t==2){
			w[f] = 1;
			w[s] = 1;
		}
	}

	dfs(0);

	//fo(i,n) cout << w[i] << " " << d[i] << endl;

	vi ans;
	fo(i,n){
		if(w[i] && d[i]==1) ans.pb(i+1);
	}
	cout << sz(ans) << endl;
	fo(i,sz(ans)) cout << ans[i] << " ";

	return 0;
} 