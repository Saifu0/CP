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

int solve(int*arr, int start, int end, int age,int**dp){
	if(start > end) return 0;

	if(dp[start][end] != -1)
		return dp[start][end];

	int ans1 = arr[start]*age + solve(arr,start+1,end,age+1,dp);
	int ans2 = arr[end]*age + solve(arr,start,end-1,age+1,dp);

	int ans= max(ans1,ans2);
	dp[start][end] = ans;

	return ans;
}

int main(){
	int n;
	cin >> n;
	int*arr = new int[n];
	fo(i,n)
		cin >> arr[i];

	int**dp = new int*[n+1];
	fo(i,n+1){
		dp[i] = new int[n+1];
		fo(j,n+1){
			dp[i][j] = -1;
		}
	}
	int ans = solve(arr,0,n-1,1,dp);

	cout << ans << endl;

	delete[] dp;
	delete[] arr;
	
	return 0;
}


