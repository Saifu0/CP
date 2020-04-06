#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll solve(ll*arr, ll n, ll m, ll start, ll* dp){
	if(n==start || start < 0) return 0;
	
	//if(dp[start] != 0) return dp[start];
	ll ans1;
	ll ans = arr[start] + solve(arr, n, m, start+1,dp);
	if(ans > m ){
		ans = ans - arr[start];
		ans1 = solve(arr,n,m,start-1,dp);
	}
		

	ll result = max(ans,ans1);
	//dp[start] = result;
	return result;	
}

//ll solve2(ll*arr, ll n, ll m, ll start, bool* visited){
//	
//	visited[start] = true;
//	ll ans += arr[start];
//
//	for(int i=0;i<n;i++){
//		if(visited[i] == false && ans <= m){
//			return solve2(arr, n, m ,i, visited);
//		}
//		ans -= arr[start];
//		visited[start] = false;
//	}
//	return ans;
//}
int main(){
	ll n,m;
	cin >> n >> m;
	ll* arr = new ll[n];
	for(int i=0;i<m;i++){
		cin >> arr[i];
	}
	ll * dp = new ll[n];
	memset(dp, 0, sizeof(n));
	ll ans = solve(arr,m,n, 0, dp);
	//bool * visited = new bool[n];
	//memset(visited, false, sizeof(n));

	//ll ans = solve(arr, m, n, 0, visited);
	cout << ans << endl;

	delete[] arr;
	delete[] dp;
}
