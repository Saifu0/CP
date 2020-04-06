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

int solve(int*arr, int m, int n, int**dp){
	if(n==0 || m == 0) return 0;

	if(dp[n][m] != -1) return dp[n][m];

	int ans;
	if(arr[n-1] > m)
		return solve(arr,m,n-1,dp);

	else
		ans = max(solve(arr,m,n-1,dp), arr[n-1] + solve(arr,m-arr[n-1], n-1, dp));

	dp[n][m] = ans;
	return ans;
}

int main(){
	int t;
	cin >> t;
	while(t--){
		int m,n;
		cin >> n >> m;
		int*arr = new int[n];

		int sum = 0;
		fo(i,n) {
			cin >> arr[i];
			sum += arr[i];
		}

		if(m>sum)
			m = sum;

		m -= arr[0];

		int**dp = new int*[n+1];
		fo(i,n+1){
			dp[i] = new int[m+1];
			fo(j,m+1){
				dp[i][j] = -1;
			}
		}

		cout << arr[0] + solve(arr+1,m,n, dp) << endl;
	}
	
	
	return 0;
}


