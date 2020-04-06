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
ll a[mxn];
int n;
int b[mxn],c[mxn];


int main(){
	c_p_c();
	cin >> n;
	
	fo(i,n){
		cin >> a[i];
		if(i==0 || a[i] <= a[i-1]){
			b[i] = 1;
		}else{
			b[i] = b[i-1] + 1;
		}
	}

	for(int i=n-1;i>=0;i--){
		if(i==n-1 || a[i] >= a[i+1]){
			c[i] = 1;
		}else{
			c[i] = c[i+1] + 1;
		}
	}

	int left,right,ans=INT_MIN;


	fo(i,n){
		if(i==0) left = 0;
		else left = b[i-1];
		if(i==n-1) right=0;
		else right =c[i+1];

		if(a[i-1] + 1 < a[i+1]){
			ans = max(ans,(left+right+1));
		}else{
			ans = max(ans,max(left,right)+1);
		}
	}

	cout << ans << endl;

	return 0;
}