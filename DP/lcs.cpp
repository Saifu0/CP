#include<bits/stdc++.h>
using namespace std;

#define deb(x) cout << #x << " " << x << endl;
#define fo(i,n) for(int i=0;i<n;i++)
#define Fo(i,k,n) for(int i=k,i<n;i++)
#define vi vector<int>
#define ii pair<int,int>
#define vii vector<ii>
#define ll long long
#define pb push_back
#define endl "\n"
#define mp map<int,int>

int solve(char*s1,int n, char*s2, int m, int**dp){
	if(n==0 || m==0) return 0;

	if(dp[n][m] != -1) return dp[n][m];

	int ans;
	if(s1[0] == s2[0]){
		ans = 1 + solve(s1 +1 ,n-1, s2+1, m-1, dp);
	}else{
		int ans1 = solve(s1+1,n-1,s2,m,dp);
		int ans2 = solve(s1,n,s2+1,m-1,dp);
		ans = max(ans1,ans2);
	}
	
	dp[n][m] = ans;
	return ans; 
}

int main(){
	char *s1 = new char[100];
	char *s2 = new char[100]; 
	cin >> s1 >> s2;

	int n = strlen(s1);
	int m = strlen(s2);
	int**dp = new int*[n+1];
	fo(i,n+1){
		dp[i] = new int[m+1];
		fo(j,m+1){
			dp[i][j] = -1;
		}
	}

	cout << solve(s1,strlen(s1),s2, strlen(s2), dp) << endl;	
	
	return 0;
}


