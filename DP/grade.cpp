#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin >> t;
	while(t--){
		int n,m;
		cin >> n >> m;
		int*arr = new int[n];
		int sum;
		for(int i=0;i<n;i++){
			cin >> arr[i];
		}
		int ans = arr[0];
		sort(arr,arr+n);
		int i=1;
		while(i<=n && ans <= m){
			if(ans + arr[i] <= m){
				ans += arr[i];
				i++;
			}else if(ans + arr[i] > m){
				ans = m;
				break;
			}
		}
		cout << ans << endl;
	}
}
