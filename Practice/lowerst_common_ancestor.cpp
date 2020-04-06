#include<bits/stdc++.h>
using namespace std;

void dfs(int u, int p, int**dp, int*lev, int log, vector<int> v[]){
	dp[u][0] = p;
	for(int i=1;i<=log;i++)
		dp[u][i] = dp[dp[u][i-1]][i-1];
	for(int i: v[u]){
		if(i!=p){
			lev[i] = lev[u] + 1;
			dfs(i,u,dp,lev,log,v);
		}
	}
}

int lca(int u, int v, int log, int *lev, int**dp){
	if(lev[u] < lev[v]) swap(u,v);

	for(int i=log;i>=0;i--){
		if((lev[u] - pow(2,i)) >= lev[v])
			u = dp[u][i];
	}

	if(u==v) return u;

	for(int i=log;i>=0;i--){
		if(dp[u][i] != dp[v][i]){
			u = dp[u][i];
			v = dp[v][i];
		}
	}

	return dp[u][0];
}

int main(){
	int t,cnt=0;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		vector<int> v[n+1];
		for(int i=1;i<=n;i++){
			int m; 
			cin >> m;
			for(int j=0;j<m;j++){
				int data;
				cin >> data;
				v[i].push_back(data);
			}
		}
		
		int*lev = new int[n+1];
		int log = (int)ceil(log2(n));
		int**dp = new int*[n+1];
		for(int i=0;i<=n;i++){
			dp[i] = new int[log+1];
			for(int j=0;j<=log;j++)
				dp[i][j] = -1;
		}

		dfs(1,1,dp,lev,log,v);
		cout << "Case " << ++cnt << ":" << endl;
		int q;
		cin >> q;
		while(q--){
			int u,f;
			cin >> u >> f;
			cout << lca(u,f,log,lev,dp) << endl;
		}
		
		
	}
}


