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

int solve(string s1, string s2, int n, int m){
	int dp[n+1][m+1];

	fo(i,n+1)
		dp[i][0] = i;

	fo(i,m+1)
		dp[0][i] = i;

	Fo(i,1,n+1){
		Fo(j,1,m+1){
			if(s1[i-1] == s2[j-1])
				dp[i][j] = dp[i-1][j-1];
			else
				dp[i][j] = 1 + min(min(dp[i-1][j], dp[i][j-1]), dp[i-1][j-1]);
		}
	}
 
	return dp[n][m];
}

int main(){
	int t;
	cin >> t;
	while(t--){
		string s1, s2;
		cin >> s1 >> s2;
		int n = s1.size();
		int m = s2.size();

		cout << solve(s1,s2,n,m) << endl;
	}	
	
	return 0;
}


