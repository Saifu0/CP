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

const int mxn = 567;
int adj[mxn][mxn];
int n;
int x[mxn];

int main(){
	c_p_c();
	cin >> n;
	fo(i,n) fo(j,n) cin >> adj[i][j];
	fo(i,n) cin >> x[i], --x[i];
	reverse(x,x+n);

	stack<ll> s;
	fo(i,n){
		fo(j,n){
			fo(k,n){
				adj[x[j]][x[k]] = min(adj[x[j]][x[k]],adj[x[j]][x[i]]+adj[x[i]][x[k]]);
			}
		}
		ll ans = 0;
		fo(j,i+1){
			fo(k,i+1){
				ans += adj[x[j]][x[k]];
			}
		}
		s.push(ans);
	}

	while(!s.empty()){
		cout << s.top() << " ";
		s.pop();
	}
	cout << endl;
	return 0;
}