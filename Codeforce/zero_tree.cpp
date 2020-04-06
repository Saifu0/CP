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

const int mxn = 2e6;
pair<ll,ll> r[mxn];
vi g[mxn];
ll c[mxn];
int n;

void dfs(int v, int p=-1){
	r[v].F = r[v].S = 0;
	fo(i,sz(g[v])){
		int u = g[v][i];
		if(u==p) continue;
		dfs(u,v);
		r[v].F=max(r[v].F,r[u].F);
		r[v].S=max(r[v].S,r[u].S);
	}
	//cout << 9 << " " << c[v] << " " << r[v].F << " " << r[v].S << endl;
	int now = c[v] - r[v].F + r[v].S;
	if(now > 0) r[v].F += now;
	else r[v].S += -now;
	//cout << 8 <<" "<< c[v] << " " << r[v].F << " " << r[v].S << endl;

}

int main(){
	c_p_c();
	cin >> n;
	fo(i,n-1){
		int f,s; cin >> f >> s;
		--f,--s;
		g[f].pb(s);
		g[s].pb(f);
	}

	fo(i,n) cin >> c[i];

	dfs(0);

	cout << r[0].F + r[0].S << endl;

	return 0;
}