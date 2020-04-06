#include<bits/stdc++.h>
using namespace std;

const int N = 100100;


int main(){
	int n,m;
	cin >> n >> m;
	int arr[N];

	int max = INT_MIN;
	for(int i=1;i<=n;i++){
		cin >> arr[i];
	}
	int cnt[N];
	for(int i=0;i<=N;i++){
		cnt[i] = -1;
	}

	 int dp[n+1];
	for(int i=0;i<=n;i++) dp[i] = 0;
	dp[n] = 1;
	cnt[arr[n]] = arr[n];
	for(int i=n-1;i>=0;i--){
		if(cnt[arr[i]] == -1)
			dp[i] = dp[i+1] + 1, cnt[arr[i]]=arr[i] ;
		else
			dp[i] = dp[i+1];
	}

	while(m--){
		int q;
		cin >> q;
		cout << dp[q] << endl;
	}
}
