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
ll n,m,a;
ll p[mxn],b[mxn];

ll check(int x){
	ll fo=0;
	fo(i,x){
		if(b[n-x+i]<p[i])
			fo += p[i] - b[n-x+i];
	}
	return fo;
}

ll solve(int x){
	ll ans = 0;
	fo(i,x) ans += p[i];
	if(a>ans) return 0;
	return ans-a; 
}

int main(){
	c_p_c();
	cin >> n >> m >> a;
	fo(i,n) cin >> b[i];
	fo(i,m) cin >> p[i];

	sort(b,b+n);
	sort(p,p+m);

	int l = 0;
	int r = min(n,m);
	while(l<r){
		m = (l+r+1);
		m /= 2;
		if(check(m)<=a) l = m; 
		else r = m-1;
	}

	cout << l << " " << solve(l) << endl;

	return 0;
}