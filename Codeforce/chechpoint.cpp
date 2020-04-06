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
//#define mod 1000000007

void c_p_c()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}

const int mxn = 1e5+7;
int n,m;
vector<vi> ans;
vi g[mxn],gt[mxn];
int cost[mxn];
vector<bool> vis1(mxn,0), vis2(mxn,0),vis(mxn,0);
stack<int> s;
#define mod 1000000007ll

int mn[mxn],c[mxn];

void dfs1(int v){
	vis1[v] = true;
	for(auto u : g[v]){
		if(!vis1[u]){
			dfs1(u);
		}
	}
	s.push(v);
}

void dfs2(int v, vi &temp){
	vis2[v] = true;
	temp.pb(v);
	for(auto u : gt[v]){
		if(!vis2[u]){
			dfs2(u,temp);
		}
	}
}

int main(){
	c_p_c();
	cin >> n;
	fo(i,n) cin >> cost[i];

	cin >> m;
	fo(i,m){
		int f,s; cin >> f >> s;
		--f,--s;
		g[f].pb(s);
		gt[s].pb(f);
	}

	fo(i,n){
		if(!vis1[i]){
			dfs1(i);
		}
	}

	while(!s.empty()){
		int t = s.top();
		s.pop();
		if(vis2[t]) continue;

		if(!vis2[t]){
			vi temp;
			dfs2(t,temp);
			// fo(i,sz(temp)) cout << temp[i] << " ";
			// cout << endl;
			ans.pb(temp);
		}
	}

	memset(mn,2000000000,sizeof(mn));

	ll a = 0,b=1;
	for(int i=0;i<ans.size();i++){
		int _min = 2000000000;
		int _b=0;
		for(int j=0;j<ans[i].size();j++){
			int w = cost[ans[i][j]];
			if(w<_min) {_min = w; _b=1;}
			else if(w==_min) _b++;
		}
		
		// for(int j=0;j<ans[i].size();j++){
		// 	int w = cost[ans[i][j]];
		// 	if(w==_min) _b++;
		// }
		a += _min;
		b*=(ll)_b;
		b%=mod;
	}

	cout << a << " " << b << endl;





	return 0;
}