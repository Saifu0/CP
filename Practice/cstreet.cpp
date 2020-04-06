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
#define MAX 1001

vector< ii > G[MAX];

int min_vertex(int key[], bool visited[], int v){
	int min = INT_MAX, min_index ;

	for(int i=1;i<=v;i++){
		if(visited[i] == false && min > key[i])
			min = key[i], min_index = i;
	}

	return min_index;
}

int solve(int v){

	int key[v+1];
	bool visited[v+1];

	for(int i=1;i<=v;i++)
		visited[i] = false, key[i] = INT_MAX;

	key[1] = 0;


	
	int tot = 0;

	for(int i=1;i<v;i++){
		int u = min_vertex(key, visited,v);

		tot += key[u];
		visited[u] = true;
		int sz = G[u].size();

		for(int j=0;j<sz;j++){
			int ex = G[u][j].first;
			int wt = G[u][j].second;
			if(visited[ex] == false && wt < key[ex])
				key[ex] = wt;
		}
	} 

	

	return tot;
}

int main(){
	int t;
	cin >> t;
	while(t--){
		int p,v,e;
		cin >> p >> v >> e;
		for(int i=1;i<=e;i++){
			int f,s,c;
			cin >> f >> s >> c;
			G[f].pb(ii(s,c));
		}

	cout << p*solve(v) << endl;

}
	
	return 0;
}


