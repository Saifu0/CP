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

const int M=1e6+5;
ll b[M];
int n; 

void solve(){
	memset(b,1,sizeof(b));
	b[1] = 0;
	for(int i=2;i*i<=M;i++){
		if(b[i])
		for(int j=i*i;j<=M;j+=i){
			b[j] = 0;
		}
	}
}

int main(){
	c_p_c();
	solve();
	cin >> n;
	
	fo(i,n){
		ll x; cin >> x;
		ll y = sqrt(x);

		if(y*y==x && b[y]) cout << "YES\n";
		else cout << "NO\n";
	}



	return 0;
}