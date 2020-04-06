#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
	int t;
	cin >> t;
	while(t--){
		ll n,d;
		cin >> n;
		ll sum = 0;
		for(int i=0;i<n;i++){
			cin >> d;
			sum = (sum%n + d%n)%n;
		}

		if(sum == 0) cout << "YES" << "\n";
		else cout << "NO" << "\n";
	}
}