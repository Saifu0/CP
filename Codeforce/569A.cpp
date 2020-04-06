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
	int n;
	cin >> n;
	ll ans=0;
	ll start=1;
	fo(i,n){
		ans += start;
		start+=2;
	}
	start=1;
	fo(i,n-1){
		ans += start;
		start+=2;
	}
	
	cout << ans << endl;
	
	return 0;
}
