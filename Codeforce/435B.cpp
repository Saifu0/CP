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

const int N = 123456;
vi g[N];
ll cnt[2] = {0};
int n;

void c_p_c()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}

void dfs(int v, int p, int c){
	cnt[c]++;
	for(int u : g[v]){
		if(u != p) dfs(u,v,!c);
	}
}

int main(){
	c_p_c();

	cin >> n;
	fo(i,n-1){
		int f,s;
		cin >> f >> s ;
		g[f].pb(s);
		g[s].pb(f);
	}

	dfs(1,0,0);

	cout << cnt[0]*cnt[1]-(n-1) << endl;

	return 0;
}