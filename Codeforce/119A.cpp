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
#define F first
#define S second
#define sz(v) (int)v.size()
#define mod 1000000007

void c_p_c()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}
int n,a,b,c; 

int solve(int p=0){
	vi dp(n+1);
	dp[0];

	Fo(i,1,n+1){
		int x=-1,y=-1,z=-1;

		if(i>=a) x=dp[i-a];
		if(i>=b) y=dp[i-b];
		if(i>=c) z=dp[i-c];
		if(x==-1 && y==-1 && z==-1) dp[i] = -1;
		else dp[i] = max({x,y,z})+1;
	}
	return dp[n];
}

int main(){
	c_p_c();

	cin >> n >> a >> b >> c;
	cout << solve() << endl;


	return 0;
}