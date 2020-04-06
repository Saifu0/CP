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

const int mxn = 4e6;
int a[mxn];
int n; 
vi g[mxn];

// int ceilInd(vi tail, int l, int r, int key){
// 	while(r-l>1){
// 		int m = l + (r-l)/2;
// 		if(tail[m]>=key) r = m;
// 		else l = m;
// 	}
// 	return r;
// }

int main(){
	c_p_c();
	cin >> n;
	fo(i,n) cin >> a[i];

	if(n==0){
		cout << 0 << endl;
		return 0;
	}

	vi tail(n,0);
	int len = 1;

	tail[0] = a[0];
	Fo(i,1,n){
		auto b = tail.begin(), e = tail.begin() + len; 
        auto it = lower_bound(b, e, a[i]);                
        if (it == tail.begin() + len) 
        tail[len++] = a[i];  
        else   
        *it = a[i];
	}

	cout << len << endl;

	return 0;
}
