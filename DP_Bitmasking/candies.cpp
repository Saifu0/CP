#include<bits/stdc++.h>
using namespace std;

long long solve(int like[][3], int N){
	long long * dp = new long long[1<<N];

	for(int i=0;i<(1<<N);i++){
		dp[i] = 0;
	}
	dp[0] = 1;
	for(int mask=0;mask<(1<<N)-1;mask++){
		int temp = mask;
		int k = 0;
		while(temp>0){
			if(temp%2 == 1) k++;
			temp = temp/2;
		}
		for(int j=0;j<N;j++){
			if(!(mask&(1<<j)) && like[k][j]){
				dp[mask|(1<<j)] += dp[mask];
			}
		}
	}
	return dp[(1<<N)-1];
}

int main(){
	int n;
	cin >> n;
	int like[n][3];
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin >> like[i][j];
		}
	}

	cout << solve(like,n) << endl; 
}