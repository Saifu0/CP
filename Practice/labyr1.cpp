#include<bits/stdc++.h>
using namespace std;

int x1;

void dfs(int x, int count, int& maxCount, vector<int> v[], bool vis[]){
	vis[x] = true;
	count++;
	for(auto i=v[x].begin(); i!= v[x].end(); i++){
		if(!vis[*i]){
			if(count >= maxCount){
				maxCount = count;
				x1 = *i;
			}
			dfs(*i,count,maxCount,v,vis);
		}
	}
}

void dfsutil(int node, int r, int& maxCount, vector<int> v[]){
	int count=0;
	bool vis[r];
	for(int i=0;i<r;i++)
		vis[i] = false;

	dfs(node, count+1,maxCount, v, vis);
}

int diameter(int r, vector<int> v[]){
	int maxCount=INT_MIN;

	dfsutil(0,r,maxCount, v);

	dfsutil(x1,r,maxCount, v);

	return maxCount;
}

int main(){
	int t;
	cin >> t;
	while(t--){
		int c,r;
		cin >> c >> r;
		vector<int> v[r];
		for(int i=0;i<r;i++){
			for(int j=0;j<c;j++){
				char c;
				cin >> c;
				if(c=='.')
				v[i].push_back(j);
			}
		}

		int maxCount = diameter(r, v);

		cout << maxCount << endl;
		for(int i=0;i<1001;i++)
			v[i].clear();
	}
}
