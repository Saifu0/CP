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

bool sieve[100000+1];

void find_prime(int n){
	for(int i=2;i<=100000;i++) sieve[i] = true;
	sieve[1] = false;
	for(int i=2;i<=sqrt(100000);i++){
		if(sieve[i]){
			for(int j=i*i;j<=100000;j+=2) sieve[j] = false;
		}
	}
}

set<int> find_factor(int n){
	set<int> v;
	for(int i=1;i<=sqrt(n);i++){
		if(n%i==0){
			if(n/i==i) v.insert(i);
			else{
				v.insert(i);
				v.insert(n/i);
			}
		}
	}
	return v;
}

int main(){
	c_p_c();
	find_prime(100000);
	int t; cin >> t;
	while(t--){
		ll x,p; cin >> x >> p;
		bool flag = false;
		Fo(i,1,100000){
			set<int> v = find_factor(i);
			//cout << v.size() << endl;
			if(v.size() < x || v.size() > x) continue;
			int prime = 0;
			for(auto j: v){
				//cout << j << " ";
				if(sieve[j]) prime++;
			}
			//cout << prime;
			if(prime < p || prime > p) continue;
			flag = true;
			break;
		}
		if(flag) cout << 1 << endl;
		else cout << 0 << endl;
		
	}

	return 0;
}