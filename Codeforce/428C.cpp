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

typedef long double ld;

const int maxn = 2e5 + 17;
vi v[maxn];

void c_p_c()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}



ld dfs(int g=0,int p=-1){
	ld sum = 0;
	for(int u: v[g]){
		if(u != p)sum +=  dfs(u,g) + 1;
	}

	return sum ? sum / (v[g].size() - (p!=-1)) : 0;
}

int main(){
	c_p_c();

	int n;
	cin >> n;

	

	fo(i,n-1){
		int f,s;
		cin >> f >> s;
		--f,--s;
		v[f].pb(s);
		v[s].pb(f);
	}

	//int x = sz(v);
	cout << fixed << setprecision(7) << dfs() << '\n';



	return 0;
}