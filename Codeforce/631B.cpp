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

const int mxn = 210000;
int a[mxn];
bool vis[mxn],ok[mxn],okk[mxn];

int main(){
	c_p_c();
	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		Fo(i,1,n+1){
			vis[i] = false;
			ok[i] = false;
			okk[i] = false;
		}

		Fo(i,1,n+1) cin >> a[i];
		int mx =0;
		int t=0;
		Fo(i,1,n+1){
			if(vis[a[i]]) break;
			vis[a[i]] = true;
			t++;
			mx = max(mx,a[i]);
			if(t==mx) ok[i] = true; 
		}
		Fo(i,1,n+1) vis[i] = false;
		mx = 0, t=0;
		for(int i=n;i>=1;i--){
			if(vis[a[i]]) break;
			vis[a[i]] = true;
			t++;
			mx = max(mx,a[i]);
			if(t==mx) okk[i] = true; 
		}
		int ans=0;
		Fo(i,1,n) if(ok[i]&&okk[i+1]) ans++;
		cout << ans << endl;
		Fo(i,1,n) if(ok[i]&&okk[i+1]) cout << i << " " << n-i << endl;
	}

	return 0;
}