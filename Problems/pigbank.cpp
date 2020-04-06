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



int main(){
	int t;
	cin >> t;
	while(t--){
		int pig,bank;
		cin >> pig >> bank;
		int W = bank-pig;
		int n;
		cin >> n;
		int *wt = new int[n];
		int*val = new int[n];

		fo(i,n){
			int data,weight;
			cin >> data >> weight;
			wt[i] = weight;
			val[i] = data;
		}

		int dp[10000];
		dp[0] = 0;

		for(int i=1;i<=W;i++){
			dp[i] = -1;
			for(int j=0;j<n;j++){
				if(i>=wt[j] && dp[i-wt[j]] != -1 && (dp[i] == -1 || val[j] + dp[i-wt[j]] <= dp[i]))
					dp[i] = val[j] + dp[i-wt[j]];
			}
		}

		if(dp[W] == -1) printf("This is impossible.\n");
		else printf("The minimum amount of money in the piggy-bank is %d.\n",dp[W]);
	}
	
	return 0;
}


