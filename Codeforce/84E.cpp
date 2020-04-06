#include<bits/stdc++.h>
using namespace std;

#define deb(x) cout << #x << " " << x << endl;
#define fo(i,n) for(int i=0;i<n;i++)
#define Fo(i,k,n) for(int i=k;i<n;i++)
#define vi vector<int>
#define ii pair<int,int>
#define vii vector<ii>
#define ll long long
#define pb push_back
#define endl "\n"
#define mp map<int,int>
#define F first
#define S second
#define sz(v) (int)v.size()
#define mod 998244353

void c_p_c()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}

ll pwmd(int a, int n){
	if(!n) return 1;
	ll p = pwmd(a,n/2);
	p *= p; p %= mod;
	if(n&1) p *= a, p%=mod;
	return p;
}

int main(){
	c_p_c();
	int n; cin >> n;

	for(ll i=1;i<=n;i++){
		ll ans = 0;
		if(i==n) ans = 10;
		else if(i==n-1) ans = 180;
		else{
			ans = 2*9*10*pwmd(10,n-i-1);
			ll rest = (n-i-1)*10*9*9*pwmd(10,n-i-2);
			ans += rest;
			ans %= mod;
		}
		cout << ans << " ";
	}

	return 0;
}