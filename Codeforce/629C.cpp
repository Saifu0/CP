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
		string s; cin >> s;
		string ans1="", ans2="";
		bool flag=false;
		fo(i,s.size()){
			if(flag==true){
				ans1 += '0';
				ans2 += s[i];
			}else if(flag==false && s[i] == '1'){
				ans1 += s[i];
				ans2 += '0';
				flag=true;
			}else{
				ans1 += to_string((s[i]-'0')/2);
				ans2 += to_string((s[i]-'0')/2);
			}
		}
		cout << ans1 << endl << ans2 << endl;
	}

	return 0;
}