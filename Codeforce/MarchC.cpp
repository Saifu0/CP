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
#define M 1000000007

void solve(){
	int n;
	cin >> n;
	int b[n];
	fo(i,n) cin >> b[i];
	
	fo(i,n-1){
		if((b[i]&b[i+1]) != b[i]){
			cout << 0 << endl;
			return;
		}
	}
	
	int c=0;
	fo(i,n-1){
		c += __builtin_popcount(b[i]);
	}
	
	int ans = 1;
	fo(i,c){
		ans = (ans*2)%M;
	}
	cout << ans << endl;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int t;
	cin >> t;
	while(t--){
		solve();
	}
	
	
	return 0;
}
