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

string reverse(string const &s)
{
	string rev;
	for (int i = s.size() - 1; i >= 0; i--) {
		rev = rev.append(1, s[i]);
	};

	return rev;
}


int solve(string s, int n, string x, int m){
	int**dp = new int*[n+1];

	fo(i,n+1){
		dp[i] = new int[n+1];
		fo(j,n+1){
			dp[i][j] = 0;
		}
	}

	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(s[i-1] == x[j-1]){
				dp[i][j] = 1 + dp[i-1][j-1];
			}else{
				dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
			}
		}
	}
	return dp[n][m];
}

int main(){
	int t;
	cin >> t;
	while(t--){
		string s;
		cin >> s;
		int n = s.length();
		string x = reverse(s);
		int**dp = new int*[n+1];
		int ans = n - solve(s,n,x,n);
		cout << ans << endl;
	}
	
	return 0;
}


