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
#define mod 1000000007

void c_p_c()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}

const int mxn = 2e5;
ll a,b;
ll l,r;
int q;
set<ll> v;
vector<ll> x;

void find_factor(){
	ll n = __gcd(a,b);

	Fo(i,1,sqrt(n)+1){
		if(n%i==0){
			if(n/i==i) v.insert(i);
			else{
				v.insert(i);
				v.insert(n/i);
			}
		}
	}
}




int main(){
	c_p_c();
	cin >> a >> b;

	find_factor();

	cin >> q;
	while(q--){
		cin >> l >> r;
		auto ind = upper_bound(v.begin(), v.end(), r);
		ind--;
		
		if(*ind < l || *ind>r) cout << -1 << endl;
		else cout << *ind << endl;
	}

	return 0;
}

