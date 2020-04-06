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

const int N = 2e5;
int n,m;
ll a[N],b[N+1], ans = 1e18;

int main(){
	c_p_c();
	cin >> n >> m;
	fo(i,n) cin >> a[i];
	//b[0] = 0;
	sort(a,a+n);
	fo(i,n) b[i+1] = b[i] + a[i];

	for(int i=0,j=0;i<n;i=j){
		for(;j<n&&a[j]==a[i];j++);
		ll c = j-i, x=a[i], cl = (ll)i*(x-1) - b[i], cr = b[n]-b[j]-(ll)(n-j)*(x+1);

		if(c>=m) ans = 0;
		if(c+i>=m) ans = min(cl+m-c,ans);
		if(c+n-j>=m) ans = min(cr+m-c,ans);
		ans = min(cl+cr+m-c,ans);
	}
	cout << max(ans,0ll) << endl;

	return 0;
}