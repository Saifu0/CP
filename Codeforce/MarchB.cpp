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
#define S second
#define F first

const int N = 123456;
vi a(N);

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		int mxn = INT_MIN;
		fo(i,n) {cin >> a[i]; mxn = max(mxn,a[i]);}
		
		int pref=0,suf=0;
		fo(i,n){
			if(a[i]==mxn) pref=i;
		}
		for(int i=n-1;i>=0;i--){
			if(a[i]==mxn) suf=i;
		}
		int ans = n/2 - (pref-suf);
		
		if(ans>=0) cout << ans << endl;
		else cout << 0 << endl; 
	}
	
	return 0;
}
