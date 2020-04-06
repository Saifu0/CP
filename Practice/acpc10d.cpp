#include<bits/stdc++.h>
using namespace std;


int main(){
	int n;
	cin >> n;
	int cnt=0;
	while(n!=0){
		int arr[n][3];
		for(int i=0;i<n;i++){
			for(int j=0;j<3;j++){
				cin >> arr[i][j];
			}
		}
		arr[0][0] = INT_MAX;
		arr[0][2] += arr[0][1];

		for(int i=1;i<n;i++){
			for(int j=0;j<3;j++){
				int l,r,m;
				l = j==0 ?  INT_MAX : arr[i-1][j-1];
				m = arr[i-1][j];
				r = j==2 ? INT_MAX : arr[i-1][j+1];
				int d = (j==0) ? INT_MAX :arr[i][j-1];
				arr[i][j] +=  min(min(l,r),min(d,m));
			}
		}
		
	//	int min = INT_MAX;
	//	for(int i=0;i<3;i++){
	//		if(dp[n-2][i] < min)
	//			min = dp[n-2][i];
	//	}
	//	cout << min + arr[n-1][1] << endl;
		cout << ++cnt << ". " <<  arr[n-1][1] << endl;
		cin >> n;		
	}
}
