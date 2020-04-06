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

int main(){
	c_p_c();

	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		int p[n+1]; int c[n+1];
		Fo(i,1,n+1) cin >> p[i];
		Fo(i,1,n+1) cin >> c[i];

		vector<bool> vis(n+1);
		map<int,vi> m;

		Fo(i,1,n+1){
			if(vis[i]) continue;

			vis[i] = 1;
			m[i].pb(i);
			int curr = i;
			while(p[curr] != i){
				curr = p[curr];
				vis[curr] = 1;
				m[i].pb(curr);
			}
		}

		int ans = n;
		for(auto el: m){
			int s = el.S.size();

			for(int i=1;i*i<=s;i++){
				int k = i;

				if(s%k!=0) continue;
				vector<bool> poss(k,1);

				fo(i,s){
					if(c[el.S[i]] != c[el.S[i%k]]) poss[i%k] = 0;
				}

				for(auto it : poss){
					if(it){
						ans = min(k,ans);
						break;
					}
				}

				k = s/k;
				poss.resize(k);
				poss.assign(k,1);

				fo(i,s){
					if(c[el.S[i]] != c[el.S[i%k]]) poss[i%k] = 0;
				}

				for(auto it : poss){
					if(it){
						ans = min(k,ans);
						break;
					}
				}

			}
		}

		cout << ans << endl;
	}

	return 0;
} 