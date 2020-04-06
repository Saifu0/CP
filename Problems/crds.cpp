#include<bits/stdc++.h>
using namespace std;

#define mod 1000007
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
	int t;
	cin >> t;
	while(t--){
		ll n;
		cin >> n;
		

		ll ans = (3*(n*(n+1))/2 - n )%mod;

		cout << ans << endl;
	}
	
	return 0;
}


