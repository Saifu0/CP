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

int b;

bool isbipartiteUtil(int color[], int index, vi g[]){
	color[index] = 1;
	queue<int> s;
	s.push(index);
	while(!s.empty()){
		int x = s.front();
		s.pop();
		for(int i=0;i<g[x].size();i++){
			if(color[g[x][i]] == -1){
				color[g[x][i]] = color[x]^1;
				s.push(g[x][i]);
			}else if(color[g[x][i]] == color[x]){
				return false;
			}
		}
	}
	return true;
}

bool isbipartite(vi g[]){
	int color[2001];
	Fo(i,1,b+1){
		color[i] = -1;
	}

	Fo(i,1,b+1){
		if(color[i] == -1){
			if(isbipartiteUtil(color,i,g) == 0){
				return false;
			}
		}
	}
	return true;
}

int main(){
	int t;
	cin >> t;
	int temp = t;
	while(t--){
		int e;
		cin >> b >> e;
		vi g[b+1];
		fo(i,e){
			int f,s;
			cin >> f >> s;
			g[f].pb(s);
			g[s].pb(f);
		}

		cout<<"Scenario #"<<temp-t<<":"<<"\n";
		if(isbipartite(g)){
			cout << "No suspicious bugs found!" << endl;
		}else{
			cout << "Suspicious bugs found!" << endl;
		}
	}
	
	return 0;
}


