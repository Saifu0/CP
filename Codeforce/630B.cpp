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
		int a[n];
		vi c(n);
		fo(i,n) cin >> a[i];
		int s = 0;
		bool vis[n] = {false};
		fo(i,n){
			if(!vis[i]){
				s++;
				c[i] = s;
				vis[i] = true;
			}
			Fo(j,i+1,n){
				if(__gcd(a[i],a[j])>1 && !vis[j]){
					c[j] = s;
					vis[j] = true;
				}
			}
		}
		set<int> st;
		fo(i,n) st.insert(c[i]);
		cout << st.size() << endl;
		fo(i,n) cout << c[i] << " ";
		cout << endl;
	}

	return 0;
}