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
		string s;
		getline(cin,s);

		while (s.length()==0 ) 
            getline(cin, s); 

		bool f=false,sec=false;
		int ind=0;

		string ans="";
		fo(i,s.size()){
			if(s[i]==' ' && f==false){
				f = true;
				ans += toupper(s[0]);
				//cout << s[0];
				ans += ". ";
				ind = i+1;

			}
			else if(s[i]==' ' && f==true){
				sec = true;
				// toupper(s[ind]);
				// cout << s[ind];
				ans += toupper(s[ind]);


				ans += ". ";
				ind = i + 1;
			}
		}
		// toupper(s[ind]);
		// cout << s[ind];
		ans += toupper(s[ind]);

		Fo(i,ind+1,s.length()){
			ans += tolower(s[i]);
			//cout << s[i];
		}
		cout << ans << endl;


	}

	return 0;
}