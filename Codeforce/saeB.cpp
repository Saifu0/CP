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
		int n; cin >> n;

		double ans = 0;
		fo(i,n){
			string s;
			getline(cin,s);

			while (s.length()==0 ) 
	            getline(cin, s);

	        bool left = (s[0]=='f' || s[0]=='d') ? true : false;
	        bool right = (s[0]=='j' || s[0]=='k') ? true : false;



	         ans += 0.2;
	        Fo(j,1,s.length()){
	        	if((s[j]=='j' || s[j]=='k' ) && right) ans += 0.4;
	        	else if((s[j]=='j' || s[j]=='k' ) && !right) ans += 0.2;
	        	else if((s[j]=='d' || s[j]=='f' ) && left) ans += 0.4;
	        	else ans += 0.2;
	        }
		}
		cout << ans << endl;
	}

	return 0;
}