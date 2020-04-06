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

int dp[1010][1010];

int solve(int h, int a, int cnt, bool f){
	if(h<=0 || a<=0) return cnt;

	if(dp[h][a] != -1){
		return dp[h][a];
	}

	if(f)
		dp[h][a] = max(dp[h][a], solve(h+3,a+2,cnt+1,!f));

	return dp[h][a] = max(dp[h][a], max(solve(h-5,a-10,cnt+1,!f),solve(h-20,a+5,cnt+1,!f)));

}

int main(){
	int t;
	cin >> t;
	while(t--) {
	    int h,a;
	    cin >> h >> a;
	   	bool f = true;
	   	memset(dp,-1,sizeof dp);

	    cout << solve(h,a,-1,f) << endl;
	}
	
	return 0;
}


