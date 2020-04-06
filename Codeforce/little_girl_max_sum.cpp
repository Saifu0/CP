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
int n,q;
ll max_i[mxn],tree[mxn],a[mxn];

void update(int x, int val){
	while(x<=n){
		tree[x] += val;
		x += (x&-x);
	}
}

ll query(int x){
	ll sum = 0;
	while(x>=1){
		sum += tree[x];
		x -= (x&-x);
	}
	return sum;
}

int main(){
	c_p_c();
	 cin >> n >> q;
	fo(i,n) cin >> a[i];
	sort(a,a+n);

	fo(i,q){
		int x,y; cin >> x >> y;
		update(x,1);
		update(y+1,-1);
	}

	fo(i,n){
		max_i[i] = query(i+1);
	}
	sort(max_i,max_i+n);

	ll ans = 0;
	fo(i,n){
		ans += (max_i[i]*a[i]);
	}
	cout << ans << endl;

	return 0;
}