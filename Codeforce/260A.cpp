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

int solve(vi v, mp m,int n, int dp[]){
	if(n==0) return 0;
	if(n==1) return m[1];

	if(dp[n] != -1) return dp[n];

	int ans1 = solve(v,m,n-1,dp);
	int ans2 = m[n]*(n) + solve(v,m,n-2,dp);

	int ans = max(ans1,ans2);
	dp[n] = ans;

	return ans;
}

int main(){
	int n;
	cin >> n;
	vi v(n+1);
	mp m;
	Fo(i,1,n+1) {
		cin >> v[i];
		m[v[i]]++;

	}	

	// for(auto it=m.begin();it!=m.end();it++){
	// 	cout << it->first << " " << it->second << endl;
	// }

	int*dp = new int[n+1];
	Fo(i,0,n+1) dp[i] = -1;

	cout << solve(v,m,n,dp) << endl;


	delete[] dp;
	
	return 0;
}


 