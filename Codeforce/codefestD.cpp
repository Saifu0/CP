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

const int N = 200007;
vi g[N],ans;
int a[N],cmp[N];
bool vis[N];

void c_p_c()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}

bool compare(int a, int b){
	return cmp[a] < cmp[b];
}

int main(){
	c_p_c();

	int n; cin >> n;
	fo(i,n-1){
		int f,s; cin >> f >> s;
		g[f].pb(s);
		g[s].pb(f);
	}

	fo(i,n){
		cin >> a[i];
		cmp[a[i]] = i;
	}

	Fo(i,1,n+1) sort(g[i].begin(),g[i].end(),compare);

	queue<int> q;
	q.push(1);
	memset(vis,false, sizeof(vis));

	while(!q.empty()){
		int x =q.front();
		q.pop();
		ans.pb(x);
		vis[x] = true;
		for(int i=0;i<g[x].size();i++){
			if(!vis[g[x][i]]) q.push(g[x][i]);
		}
	} 

	fo(i,n){
		if(ans[i] != a[i]){
			puts("No");
			return 0;
		}
	}

	puts("Yes");

	return 0;
}