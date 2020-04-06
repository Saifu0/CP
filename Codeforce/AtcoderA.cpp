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

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n,m;
	cin >> n >> m;
	ll ans = 0;
		
	if(n!=0)
	for(int i=n-1;i>=1;i--) ans += i;
	
	if(m!=0)
	for(int i=m-1;i>=1;i--) ans += i;
	
	cout << ans << endl;
	
	return 0;
}
