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

const int mxn = 5e6;
map<int,int> m;
int a[mxn],b[mxn];

//bool vis[mxn];

int main(){
	c_p_c();
	int n; cin >> n;
	// Fo(i,1,n+1){
	// 	cin >> a[i];
	// 	b[i] = a[i];
	// 	m[a[i]] = i;
	// }

	// sort(a,a+n);

	// int j=1;
	// ll cnt = 0;
	// auto it = m.begin();

	// fo(i,n){
	// 	if(m[i+1]){
	// 		m[i+1] = 0;
	// 		b[m[i+1]] = INT_MAX;
	// 		continue;
	// 	}
	// 	while(b[j]==INT_MAX) j++;
	// 	cnt += abs(i+1-a[j]);
	// 	a[j] = INT_MAX;
	// 	j++;
	// }

	// fo(i,n) cout << a[i] << " ";
	// cout << endl;

	// cout << cnt << endl;

	fo(i,n){
		cin >> a[i];
	}

	sort(a,a+n);
	ll cnt = 0;
	fo(i,n){
		cnt += abs(a[i]-(i+1));
	}

	cout << cnt << endl;

	return 0;
}