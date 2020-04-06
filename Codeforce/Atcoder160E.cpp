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
int x,y,a,b,c;
const int N = 2e5;
ll p[N],q[N],r[N];

bool cmp(ll l, ll m){
	return l > m;
}

int main(){
	c_p_c();

	
	cin >> x >> y >> a >> b >> c;
	fo(i,a) cin >> p[i];
	fo(i,b) cin >> q[i];
	fo(i,c) cin >> r[i];
	sort(p,p+a,cmp);
	sort(q,q+b,cmp);
	p[a]=q[b]=1e9;
	//c = max(x+y,c);
	sort(r,r+c,cmp);

	ll ans = 0;
	int i=0,j=0;
	for(;i<x;i++) ans += p[i];
	for(;j<y;j++) ans += q[j];
	--i,--j;
	for(int k=0,j1=x-1,j2=y-1;k<x+y;k++){
		if(r[k]<=p[j1] && r[k]<=q[j2]) break;
		ans += r[k];
		if(p[j1]<q[j2]) ans -= p[j1--];
		else ans -= q[j2--];
	}


	cout << ans << endl;
	return 0;
}