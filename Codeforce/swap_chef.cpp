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
	int t; cin >> t;
	while(t--){
		int n,m; cin >> n >> m;
		int ans = n + m;

		int a = n/10;
		int b = n%10;
		int c = m/10;
		int d = m%10;

		if(n/10==0 && m/10==0){
			cout << ans << endl;
			continue;
		}

		if(n/10==0 || m/10==0){
			if(n/10==0){
				ans = max(ans,c+(b*10+d));
				ans = max(ans,d+(c*10+b));
			}else{
				ans = max(ans,(a*10+d)+b);
				ans = max(ans,(d*10+b)+a);
			}
			cout << ans << endl;
			continue;
		}
		

		ans = max(ans,(a*10+c)+(b*10+d));
		ans = max(ans,(a*10+d)+(c*10+b));
		ans = max(ans,(c*10+b)+(a*10+d));
		ans = max(ans,(d*10+b)+(c*10+a));

		cout << ans << endl;
	}

	return 0;
}