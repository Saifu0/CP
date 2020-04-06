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


int solve(int n, int wt[], int val[], int pb){
	int dp[n+1][pb+1];
	memset(dp,0,sizeof(dp));


	for(int i=1;i<=n;i++){
		for(int j=1;j<=pb;j++){
			if(wt[i-1] <= j){
				dp[i][j] = max(val[i-1] + dp[i-1][j-wt[i-1]], dp[i-1][j]);
			}else{
				dp[i][j] = dp[i-1][j];
			}
		}
	}

	int max = dp[n][pb];
	int min = 0;

	for(int i=0;i<=pb;i++){
		if(dp[n][i] == max){
			min = i;
			break;
		}
	}
	cout << min << " ";
	return max;
}

int main(){
	int budget,party;
	cin >> budget >> party;
	while(budget!=0 && party!=0){
		int wt[party],val[party];
		fo(i,party){
			int weight,cost;
			cin >> weight >> cost;
			wt[i] = weight;
			val[i] = cost;
		}

		int ans =  solve(party,wt,val, budget);

		cout << ans << endl;

		cin >> budget >> party;
	}
	
	return 0;
}


