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
	int n,k,c; cin >> n >> k >> c;
	string s; cin >> s;
	vi store;
	int t = INT_MAX;
	int cnt = 0;
	fo(i,n){
		if(s[i]=='o' && t>=c){
			cnt++;
			t=0;
			store.pb(i);
		}else{
			t++;
		}
	}

	cnt = 0, t=INT_MAX;
	reverse(s.begin(),s.end());
	fo(i,n){
		if(s[i]=='o' && t>=c){
			cnt++;
			t = 0;
			store.pb(n-i-1);
		}else{
			t++;
		}
	}

	if(cnt==k){
		int cnti[200001] = {0};
		fo(i,sz(store)) cnti[store[i]]++;
		fo(i,n){
			if(cnti[i]==2) cout << i+1 << endl;
		}
	}




	return 0;
}