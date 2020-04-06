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
	string s; cin >> s;
	int n = sz(s);

	int total = 0;
	int pos = -1;


	fo(i,n){
		total += (s[i]=='(' ? 1 : -1);
		if(s[i]=='#') pos = i;
	}

	if(total < 0){
		cout << -1 << endl;
		return 0;
	}

	int last = total +1;
	total = 0;
	fo(i,n){
		total += ( i== pos ? -last : (s[i]=='(' ? 1  : -1));
		if(total<0){
			printf("-1\n");
			return 0;
		}
	}

	fo(i,n){
		if(s[i]=='#'){
			if(i==pos){
				cout << last << endl;
			}else{
				cout << 1 << endl;
			}
		}
		
	}
	return 0;
}