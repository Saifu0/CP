#include<bits/stdc++.h>
using namespace std;

#define sc(x) scanf("%d",&x)
#define pf(c) scanf("%d",x);
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

const int N = 12345;

int solve(int dp[], int n, int d){
	if(n<0) return 0;
	if(n==0) return 1;
	//else return 0;
	
	if(dp[n] != -1) return dp[n];
	
	int sum=0;
	
	for(int i=2;i<=d;i+=2){
		sum += solve(dp,n-i,d);
	}
	
	return sum;
}


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	while(t--){
		int n,d;
		cin >> n >> d;
		int dp[N+1];
		for(int i=0;i<=N;i++) dp[i] = -1;
		cout << solve(dp,n,d) << endl;
	}
	
	return 0;
}
