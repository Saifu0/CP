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

int main(){
	c_p_c();
	ll a,b,c; cin >> a >> b >> c;


	if(max({a,b,c}) >= 2*(a+b+c-max({a,b,c}))){
		cout << (a+b+c)-max({a,b,c}) << endl;
		return 0;
	}

	ll n = (a/3) + (b/3) + (c/3);
	n += (a%3 + b%3 + c%3)/3; 
	cout << n << endl;

	return 0;
}