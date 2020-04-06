#include<bits/stdc++.h>
using namespace std;

#define ll long long 

int main(){
	int n;
	cin >> n;
	int arr[n];
	ll sum = 0;
	ll s[n+1];
	s[0] = 0;
	for(int i=0;i<n;i++) cin >> arr[i], s[i+1] = s[i] + arr[i];
	
	ll cnt=0;
	if(s[n]%3==0){
		ll u = s[n]/3, v = 2*s[n]/3;
		int c=0;
		for(int i=1;i<n;i++){
			if(s[i] == v) cnt += c;
		       	if(s[i] == u) c++;	
		}
	}
	cout << cnt << endl;
}
