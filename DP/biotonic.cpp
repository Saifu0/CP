#include<bits/stdc++.h>
using namespace std;

int solve(int*arr, int n){
	int *dp1 = new int[n];
	for(int i=0;i<n;i++){
		dp1[i] = 1;
	}

	for(int i=1;i<n;i++){
		for(int j=0;j<i;j++){
			if(arr[i] > arr[j] && dp1[i] < dp1[j]+1)
				dp1[i] = dp1[j]+1;
		}
	}

	
	int *dp2 = new int[n];
	for(int i=0;i<n;i++){
		dp2[i] = 1;
	}


	for(int i=n-2;i>=0;i--){
		for(int j=n-1;j>i;j--){
			if(arr[i] > arr[j] && dp2[i] < dp2[j]  +1)
				dp2[i] = dp2[j]  +1;
		}
	}

	int max= INT_MIN;
	for(int i=0;i<n;i++){
		if(max < dp1[i]+ dp2[i] -1)
			max = dp1[i]+ dp2[i] -1;
	}

	return max;
}

int main(){

	int n;
	cin >> n;
	int*arr = new int[n];

	for(int i=0;i<n;i++)
		cin >> arr[i];

	cout << solve(arr,n) << endl;
}