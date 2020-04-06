#include<bits/stdc++.h>
using namespace std;
#define ll long long

const int N = 100500;

int main(){
	ll n,k;
	cin >> n >> k;
	ll a[N];
	for(int i=0;i<n;i++) cin >> a[i];

	ll ans=0; ll temp=0; ll start=0; ll max = INT_MIN;
	for(ll i=0;i<n;i++){
		temp += a[i];
		ans++;
		while(temp > k){
			temp -= a[start];
			start++;
			ans--;
		}
	       if(max < ans) max = ans;	
	}
	cout <<max << "\n";
}
