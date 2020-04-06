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
// #ifndef ONLINE_JUDGE
// 	freopen("input.txt", "r", stdin);
// 	freopen("output.txt", "w", stdout);
// #endif
}

int main(){
	c_p_c();
	int t; cin >> t;
	while(t--){
		string s; cin >> s;
		int l = 0, r = s.size()-1;

		map<char, int> m;
		while(l<r){
			m[s[l]] += 1;
			m[s[r]] += 1;
			l++; r--;
		}

		int flag = false;
		for(auto it=m.begin();it!=m.end();it++){
			if(it->S%2!=0){
				cout << "NO\n";
				flag = true;
				break;
				//continue;
			}
		}
		if(flag==true) continue;
		cout << "YES\n";
	}

	return 0;
}