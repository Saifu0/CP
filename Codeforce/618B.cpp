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

const int N = 234567;


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

	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		vi v;
		int x;
		fo(i,2*n) cin >> x , v.pb(x);
		sort(v.begin(),v.end());

		int mn = INT_MAX;
		int m1 = v[n];
		int m2 = v[n-1];

		fo(i,2*n){
			if(v[i]<m1) mn = min(mn,abs(v[i]-m1));
			else mn = min(mn,abs(v[i]-m2));
		}

		cout << mn << endl;
		v.clear();
	}

	return 0;
}