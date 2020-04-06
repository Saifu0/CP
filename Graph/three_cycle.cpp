#include<bits/stdc++.h>
using namespace std;

int solve(int n,int m,vector<int>u,vector<int>v)
{
	int matrix[n+1][n+1] = {0};
	for(int i=1;i<=m;i++){
		matrix[u[i]][v[i]] = 1;
		matrix[v[i]][u[i]] = 1;
	}
	int count = 0;

	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(matrix[i][j] == 1){
				for(int k=1;k<=n;k++){
					if(matrix[j][k] == 1 && matrix[i][k] == 1)
						count++;
				}
			}
		}
	}

	return count;
}

int main(){
	int n,m;
	cin >> n >> m;
	vector<int> u(m+1);
	vector<int> v(m+1);
	for(int i=1;i<=m;i++){
		cin >> u[i];
	}
	for(int i=1;i<=m;i++){
		cin >> v[i];
	}

	cout << solve(n,m,u,v) << endl;
}