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

const int mxn = 2e6;
int n,m;
map<int,bool> g[mxn];
int c[mxn];

int main(){
	c_p_c();
	cin >> n >> m;
	fo(i,n) cin >> c[i];

	fo(i,m){
		int x,y; cin >> x >> y;
		--x,--y;
		int ca=c[x],cb=c[y];
		if(ca!=cb){
			g[ca][cb] = 1;
			g[cb][ca] = 1;
		}
	}

	// for(auto u : g){
	// 	for(auto i  : u){
	// 		cout << i << " ";
	// 	}
	// 	cout << endl;
	// }


	int best = *min_element(c,c+n);

	// cout << g[3].size() << endl;
	// cout << best << endl;

	fo(i,n){
		if(!best || g[c[i]].size() > g[best].size()) best = c[i];
	}
	cout << best << endl;
    
	return 0;
} 