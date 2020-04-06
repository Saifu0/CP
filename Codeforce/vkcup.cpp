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

	int n;
	cin >> n;
	string a,b,c;
	map<string,int> l;
	l["polycarp"] = 1;

	int ans = 1;
	while(n--){
		cin >> a >> b >> c;
		fo(i,c.size()) c[i] = tolower(c[i]);
		fo(i,a.size()) a[i] = tolower(a[i]);

		int e = l[c] + 1;
		if(e> ans) ans = e;
		l[a] = e;
	}
	cout << ans << endl;

	return 0;
}