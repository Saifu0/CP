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

ll a[1000];
ll dp[1000][1000];

ll sum(int s, int e){
	ll ans=0;
	for(int i=s;i<=e;i++){
		ans += a[i];
		ans %= 100;
	}
	return ans;
}

ll solve(int start, int end){
	if(start == end) return 0;


	if(dp[start][end] != -1) return dp[start][end];

	dp[start][end] = INT_MAX;
	for(int k= start;k<=end;k++){
		dp[start][end] = min(dp[start][end], solve(start,k) + solve(k+1,end) + sum(start,k)*sum(k+1,end));
	}

	return dp[start][end];
}

int main(){
	int n;
	while(scanf("%d",&n) != EOF){
		fo(i,n)
			cin >> a[i];

		fo(i,n)
			fo(j,n)
				dp[i][j]  = -1;

		cout << solve(0,n-1) << endl;
	}
	
	return 0;
}


