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

const int mxn  = 2e5;
int a[mxn];

int main(){
	c_p_c();

	int n; cin >> n;
	vi a(n);
	fo(i,n) cin >> a[i];
	vi next(n);
	fo(i,n) next[i] = i+1;
	vi d(n),k;
	fo(i,n-1){
		if(a[i]>a[i+1]) k.pb(i);
	}

	int ans = 0;
	while(sz(k)!=0){
		ans++;
		for(int i=sz(k)-1;i>=0;i--){
			d[next[k[i]]] = 1;
			next[k[i]] = next[next[k[i]]];
		}

		vi nk;
		fo(i,sz(k)){
			if(d[k[i]]==0 && next[k[i]] < n && a[k[i]] > a[next[k[i]]]) nk.pb(k[i]);
		}
		k.clear();
		fo(i,sz(nk)) k.pb(nk[i]);
	}
	cout << ans << endl;
	return 0;
}