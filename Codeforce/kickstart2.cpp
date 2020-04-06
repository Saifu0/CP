#include<bits/stdc++.h>
using namespace std;

#define sc(x) scanf("%d",&x)
#define pf(c) scanf("%d",x);
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

ll solve(vector<int> v[], int n, int s, int k, int p,ll*dp){
	if(n==0 || p==0) return 0;
	
	
	
	if(dp[p] != -1) return dp[p];
	
	ll ans=0;
	
	if(s==k) return solve(v,n-1,0,k,p,dp);
	
	ans = v[n-1][s] + solve(v,n,s+1,k,p-1,dp);
	ans= max(ans,solve(v,n-1,0,k,p,dp));
	
	dp[p] = ans;
	
	return ans;
}


int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int t;
	cin >> t;
	int start=1;
	while(t--){
		int n,k,p;
		cin >> n >> k >> p;
		vector<int> v[n];
		
		fo(i,n){
			fo(j,k){
				int d;
				cin >> d;
				v[i].pb(d);
			}
		}
		
		ll*dp = new ll[p+10];
		fo(i,p+10) dp[i] = -1;
		// Fo(i,0,k+10){
			// dp[i] = new ll[p+10];
			// Fo(j,0,p+10){
				// dp[i][j] = -1;
			// }
		// }
		
		ll ans = solve(v,n,0,k,p,dp);
		
		cout << "Case #" << start++ << ": " << ans << endl;
	}
	
	return 0;
}
