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

int main(){
	int n;
	cin >> n;
	while(n--){
		ll x,mod;
		cin >> x >> mod;
		ll ans = 1;
		for(int i=x;i>=1;i--){
			ans = (ans*i)%mod;
		}

		cout << ans << endl;
	}
	
	return 0;
}

