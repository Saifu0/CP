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

const int mxn = 4e6;

int main(){
	c_p_c();
	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		string s; cin >> s;
		//vector<bool> vis(mxn,false);

		int d; cin >> d;
		// fo(i,d){
		// 	int a; cin >> a;
		// 	if(a-2>=0) vis[a-2] = true;

		// 	fo(j,n){
		// 		if(s[j]=='1'){
		// 			if(s[j]=='1' && j-1>=0 && vis[j-1]==false ){
		// 				s[j-1]='1';
		// 			}
		// 			//if(vis[j]==true) continue;
		// 			// if(vis[j]==true){
		// 			// 	s[j+1] = '1';
		// 			// 	continue;
		// 			// }
		// 			if(s[j+1]=='1' ||  (vis[j]==true && s[j]=='1')) continue;
		// 			if(s[j]=='1' && j+1<n && vis[j+1]==false){
		// 				s[j+1] = '1';
		// 				j++;
		// 			}
		// 		}
		// 	}
		// }

		// int cnt=0;
		// fo(i,n){
		// 	//cout << s[i] << " ";
		// 	//cout << vis[i] << endl;
		// 	if(s[i]=='1') cnt++;
		// }
		//cout << cnt << endl;

		int cnt = 0;
		fo(i,d){
			int a; cin >> a;
			if(a-1>=0){
				if(s[a-1]=='1') {
					cnt++;
					//s[a-2]='@';
				}else{
					s[a-1]='@';
				}
			}
			fo(j,n){
				if(s[j]=='1'){
					if(s[j-1]=='@') cnt++;
					if(j-1>=0 && s[j-1]!='@') s[j-1] = '1';
					if(j+1<n && s[j+1]!='@') {s[j+1]='1'; j++; }
				}
			}
		}
		cout << cnt << endl;
		 cout << s << endl;
	}

	return 0;
}