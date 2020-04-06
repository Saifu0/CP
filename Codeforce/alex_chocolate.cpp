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

ll n,a,b,c,d;

int main(){
	c_p_c();

	cin >> n >> a >> b >> c >> d;
	if(n==1){
		cout << c << endl;
		return 0;
	}
	if(n==2){
		cout << d <<endl;
	}

	Fo(i,3,n+1){
		ll temp = d;
		d = ((a*c)%mod + (b*d)%mod)%mod;
		c = d;
	}
	cout << d << endl;


	return 0;
}