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

const int mxn = 1000009;
int prime[mxn];

void sieve(){
	vector<bool> a(mxn,true);

	for(int i=2;i<=sqrt(mxn);i++){
		if(a[i]){
			for(int j=i*i;j<=mxn;j+=i){
				a[j] = false;
			}
		}
	}

	for(int i=2;i<=mxn;i++){
		if(a[i]) prime[i]++;
	}

	for(int i=2;i<=mxn;i++){
		prime[i] += prime[i-1];
	}
}

int main(){
	c_p_c();
	sieve();
	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		cout << prime[n] << endl;
	}

	return 0;
}