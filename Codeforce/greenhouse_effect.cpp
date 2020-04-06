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

const int mxn = 5678;
int n,m;
int type[mxn],dp[mxn];

int main(){
	c_p_c();
	cin >> n >> m;

	Fo(i,1,n+1){
		double x; cin >> type[i];
		cin >> x;
	}

	Fo(i,1,n+1){
		int j=type[i];
		for(int k=j;k>=1;k--){
			dp[j] = max(dp[j],1+dp[k]);
		}
	}

	int ans = 0;
	Fo(i,1,n+1){
		if(dp[i]>ans) ans = dp[i];
	}

	cout << n-ans << endl;

	return 0;
}