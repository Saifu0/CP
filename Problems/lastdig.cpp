#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll power(ll a, ll b){
	ll res = 1;
	a = a%10;

	while(b>0){
		if(b&1){
			res = (res*a)%10;
		}

		b = b>>1;
		a = (a*a)%10;
	}
	return res;
}

int main(){
	int  t;
	cin >> t;
	while(t--){
		ll a,b;
		cin >> a >> b;
		cout << power(a,b) << "\n";
	}
}