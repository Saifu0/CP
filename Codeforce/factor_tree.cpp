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

const int mxn = 5e6;
vi g[mxn];
vi s;
vector<bool> vis(mxn,false);

ll find_factor(ll n){
	ll cnt = 0;
	for(ll i=1;i<=sqrt(n);i++){
		if(n%i==0){
			if(n/i==i) cnt++;
			else cnt += 2;
		}
	}
	return cnt;
}

void dfs(int l, int r){
	s.pb(l);
	if(l==r){
		return;
	}
	vis[l] = true;
	int flag = 0;
	if(!g[l].empty()){
		fo(i,sz(g[l])){
			if(!vis[g[l][i]]){
				dfs(g[l][i],r);
				flag = 1;
			}
		}
	}
	if(flag==0) s.pop_back();
}

int main(){
	c_p_c();
	int t; cin >> t;
	while(t--){
		int n; cin >> n;

		fo(i,n-1){
			int f,s; cin >> f >> s;
			g[f].pb(s);
			g[s].pb(f);
		}
		vi cost(n+1);
		Fo(i,1,n+1) cin >> cost[i];

		int q; cin >> q;

		while(q--){
			int l,r; cin >> l >> r;
			dfs(l,r);
			ll mul =1;
			ll ans = 0;
			for(auto i: s ){
				ans += find_factor(cost[i]);
			}

			if(s.size()>2)
		 	cout << ans+1 << endl;
		 	else
	 		cout << ans << endl;

			s.clear();
			vis.clear();
		}
		for(auto i: g) i.clear();
	}

	return 0;
}