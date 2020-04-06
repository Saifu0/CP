#include<bits/stdc++.h>
using namespace std;

int arr[105][105];
int main(){
	int n,e,t,m;
	cin >> n >> e >> t >> m;
	memset(arr,32,sizeof arr);
	arr[e][e] = 0;
	for(int i=0;i<m;i++){
		int u,v,cost;
		cin >> u >> v >> cost;
		arr[u][v] = cost;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			for(int k=1;k<=n;k++){
				arr[j][k] = min(arr[j][k] , arr[j][i] + arr[i][k]); 
			}
		}
	}
	int cnt=0;
	for(int i=1;i<=n;i++)
		if(arr[i][e] <= t) cnt++;
	cout << cnt << endl;
}
