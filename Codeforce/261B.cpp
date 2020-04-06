#include<bits/stdc++.h>
using namespace std;

int main(){
	long long n;
	cin >> n;
	int*arr = new int[n];
	int mn = INT_MAX;
	int mx = INT_MIN;
	for(int i=0;i<n;i++){
		cin >> arr[i];
		mn=min(mn,arr[i]);
		mx=max(mx,arr[i]);
	}
	long long t1=0,t2=0;
	for(int i=0;i<n;i++){
		t1 += (mx==arr[i]);
		t2 += (mn==arr[i]);
	}

	if(mx==mn)
		cout << mx-mn << " " << n*(n-1)/2 << "\n";
	else {
		long long cnt = t1*t2;
		cout << mx-mn << " " << cnt << "\n";
	}
	delete[] arr;
	
}
