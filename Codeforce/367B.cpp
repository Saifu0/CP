#include<bits/stdc++.h>
using namespace std;


int main(){
	int n;
	cin >> n;
	int*arr = new int[n];
	int max = INT_MIN;
	for(int i=0;i<n;i++){
		cin >> arr[i];
		if(arr[i] > max) max = arr[i];
	}
	sort(arr,arr+n);
	int cnt[max+1];
	int j = 0;
	for(int i=0;i<=max;i++) cnt[i] = 0;
	for(int i=1;i<=max;i++){
		if(arr[j]==i){
			cnt[i] = cnt[i-1] + 1;
			j++;
			continue;
		}
		cnt[i] = cnt[i-1];
	}
	int q;
	cin >> q;
	while(q--){
		int m;
		cin >> m;
		if(m >= max) cout << n << endl;
		else cout << cnt[m] << endl;
	}
}
