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

const int mxn = 2e6;
map<ii,int> m,ok;
ii q[mxn];

void bfs(int a, int b){
	m[{a,b}] = 0;
	int h=0,t=0;
	q[t++] = {a,b};

	while(h<t){
		int x = q[h].F;
		int y = q[h++].S;

		for(int i=-1;i<=1;i++){
			for(int j=-1;j<=1;j++){
				if(m.count({x+i,y+j})==0 && ok[{x+i,y+j}]){
					m[{x+i,y+j}] = m[{x,y}] + 1;
					q[t++] = {x+i,y+j};
				}
			}
		}
	}
}

int main(){
	c_p_c();
	int a,b,c,d; cin >> a >> b >> c >> d;

	int t; cin >> t;
	while(t--){
		int r,x,y; cin >> r >> x >> y;
		Fo(i,x,y+1) ok[{r,i}] = 1;
	}

	bfs(a,b);

	if(m.count({c,d})==0) cout << -1 << endl;
	else cout << m[{c,d}] << endl;

	return 0;
}