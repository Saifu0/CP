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

const int mxn = 56;
int a[mxn];

int main(){
	c_p_c();
	int b,s; cin >> b >> s;
	fo(i,s) cin >> a[i];
	sort(a,a+s);


	if(b==1){
		cout << a[0] << endl;
		return 0;
	}
	// if(b==2){
	// 	cout << abs(a[0]-a[1]) << endl;
	// 	return 0;
	// }

	int mn =INT_MAX;
	
	fo(i,s-b+1){
		if(abs(a[i]-a[i+b-1]) < mn) mn = abs(a[i]-a[i+b-1]);
	}

	cout << mn << endl;

	return 0;
}