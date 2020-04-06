#include<bits/stdc++.h>
using namespace std;

#define sc(x) scanf("%d",&x)
#define pf(c) scanf("%d",x);
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

const int mx = 234567;

ll a[mx],b[mx];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	fo(i,n) cin >> b[i];
	
	ll mxn=b[0];
	a[0] = b[0];
	Fo(i,1,n){
		
		a[i] = b[i] + mxn;
		if(a[i] > mxn) mxn = a[i];
	}
	
	fo(i,n) cout << a[i] << " ";
	cout << endl;
	
	
	return 0;
}
