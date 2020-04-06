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
	int start = 1;
	while(t--){
		string s; cin >> s;
		string ans = "";
		int n = s.size();

		fo(i,n){
			int x = s[i] - '0';
			if(x==0){
				ans += s[i];
				continue;
			}
			if(x!=0 && (i==0 || x > s[i-1]-'0')){
				if(i>0)
				fo(j,abs(x-(s[i-1]-'0'))) ans += '(' ;
				else ans += '(' ;
				ans += s[i];
			} 
			if(x!=0 && s[i-1]-'0' == x) ans += s[i];
		}
		int cnt = 0;
		string str = "";
		fo(i,sz(ans)){
			if(ans[i]=='(') { str += '('; cnt++;}
			else if(ans[i]=='0'){
				fo(j,cnt) str += ')' ;
				cnt = 0;
				str += '0';
			}else if(i+1==sz(ans)){
				str += ans[i];
				fo(j,cnt) str += ')';
			}
			else{
				str += ans[i];
			}
		}
		cout << "Case #" << start++ << ": " <<  str << endl;
	}

	return 0;
}