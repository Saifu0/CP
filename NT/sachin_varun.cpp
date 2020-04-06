#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

class Triplet {
public:
	ll x,y,ans;
};

Triplet extendEuclid(ll a,ll b){

	if(b==0){
		Triplet answer;
		answer.ans = a;
		answer.x = 1;
		answer.y = 0;
		return answer;
	}

	Triplet smallAns = extendEuclid(b,a%b);
	Triplet answer;

	answer.ans = smallAns.ans;
	answer.x = smallAns.y;
	answer.y = smallAns.x - (a/b)*smallAns.y;

	return answer;
}

ll modInverse(ll a, ll b){
	ll x = extendEuclid(a,b).x;
	return (x%b + b )%b;
}

// int ___gcd(ll a, ll b){
// 	if(b == 0){
// 		return a;
// 	}
// 	return ___gcd(b,a%b);
// }

int main(){
	int t;
	cin >> t;
	while(t--){
		ll a,b,d;
		cin >> a >> b >> d;
		ll g = __gcd(a,b);
		if(d%g){
			cout << 0 << endl;
			continue;
		}
		if(d == 0){
			cout << 1 << endl;
			continue;
		}
		a /= g;
		b /= g;
		d /= g;

		ll y1 = ((d%a)* modInverse(b,a))%a;
		if(d < y1*b){
			cout << 0 << endl;
			continue;
		}

		ll n = (d/b-y1)/a;

		cout << n + 1 << endl;


	}	
}