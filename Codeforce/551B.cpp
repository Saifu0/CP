#include<bits/stdc++.h>
using namespace std;

int main(){
	int n,m,h;
	cin >> n >> m >> h;
	int*front = new int[m];
	for(int i=0;i<m;i++)
		cin >> front[i];
	int*left = new int[n];
	for(int i=0;i<n;i++)
		cin >> left[i];
	int**g = new int*[n];
	for(int i=0;i<n;i++){
		g[i] = new int[m];
		for(int j=0;j<m;j++){
			cin >> g[i][j];
		}
	}
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			if(g[j][i]){
				int ch = max(left[j],front[i]);
				ch = ch ? h : min(left[j],front[i]) : c;
				g[j][i]
			}
		}
	}
}
