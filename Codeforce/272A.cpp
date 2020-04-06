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

int main(){
	c_p_c();
	int n,m; cin >> n >> m;
	if(n<m){
		cout << -1 << endl;
		return 0;
	}
	int ans = 0;
	int temp = n;
	while(n!=0){
		if(n>=2){
			n -= 2;
			ans++;
		}else{
			n -= 1;
			ans++;
		}
	}

	while(ans%m!=0){
		ans++;
	}


	cout << ans << endl;

	return 0;
}