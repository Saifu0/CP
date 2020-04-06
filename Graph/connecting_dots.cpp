#include<bits/stdc++.h>
using namespace std;

bool searches(char board[][51], int r, int c, int n, int m){
	
}

int solve(char board[][51], int n, int m){
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(searches(board, i, j, n, m))
				return 1;
		}
	}
	return 0;
}

int main(){
	int n,m;
	cin >> n >> m;
	char board[][m] = { {"AAAA"}, {"ABCA"}, {"AAAA"}};
	cout << solve(board, n, m) << endl;
}