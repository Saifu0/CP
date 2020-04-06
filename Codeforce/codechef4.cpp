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

int solve(int n, int w, vi wt, vi cost, int x, int y, int**dp){
	if(n==0 || w==0) return 0;
	
	if(dp[w][n] != -1) return dp[w][n];
	
	int ans;
	if(wt[n-1] > w){
		ans = solve(n-1,w,wt,cost,x,y,dp);
	}else{
		int ans1 = cost[n-1]*x + solve(n-1,w-wt[n-1],wt,cost,1,y,dp);
		int ans2 = cost[n-1]*y + solve(n-1,w-wt[n-1],wt,cost,x,1,dp);
		ans = max(max(ans1,ans2),solve(n-1,w,wt,cost,x,y,dp));
	}
	dp[w][n] = ans;
	return ans;
}

int main(){
	int t;
	cin >> t;
	while(t--){
		int n,w,x,y;
		cin >> n >> w >> x >> y;
		vector<int> wt(n),cost(n);
		fo(i,n) cin >> wt[i];
		//int mx=0,ind;
		
		fo(i,n){
			cin >> cost[i]; 
		}
		
		int** dp= new int*[w+1];
		for(int i=0;i<=w;i++){
			dp[i] = new int[n+1];
			for(int j=0;j<=n;j++){
				dp[i][j] = -1;
			}
		}
		cout << solve(n,w,wt,cost,x,y,dp) << endl;
	}
	
	return 0;
}
