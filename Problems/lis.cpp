#include<bits/stdc++.h>
using namespace std;

int lis(int* arr, int n){
	int * dp = new int[n];
	dp[0] = 1;

	for(int i=1;i<n;i++){
		dp[i] = 1;
		for(int j=i-1;j>=0;j--){
			if(arr[j] > arr[i]) continue;
			int ans = dp[j] + 1;
			if(ans > dp[i]) dp[i] = ans;
		}
	}
	int best = 0;
	for(int i=0;i<n;i++){
		if(best < dp[i]){
			best = dp[i];
		}
	}

	return best;
}

int main(){
	int n;
	cin >> n;
	int* arr = new int[n];
	for(int i=0;i<n;i++)
		cin >> arr[i];
	cout << lis(arr, n) << endl;
}