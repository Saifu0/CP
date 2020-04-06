#include<bits/stdc++.h>
using namespace std;

int x[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int y[] = {-1, 0, 1, -1, 1, -1, 0, 1};

bool search(char graph[][101], int r, int c, string word, int N, int M){
	if(graph[r][c] != word[0]) return false;

	int len = word.length();

	for(int dir = 0; dir < 8; dir++){
		int k, rd = r + x[dir], cd = c + y[dir];

		for(k=0;k<len;k++){
			if(rd >= N || rd < 0 || cd >= M || cd < 0 )
				break;

			if(graph[rd][cd] != word[k])
				break;

			rd += x[dir], cd += y[dir];
		}

		if(k==len) return true;
	}
	return false;
}

int solve(char graph[][101], int N, int M){
	string word = "CODINGNINJA";
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			if(search(graph,i,j,word,N,M)){
				return 1;
			}
		}
	}
	return 0;
}


int main(){
	int n,m;
	cin >> n >> m;
	char graph[101][101] = {"CXDXNXNXNXA","XOXIXGXIXJX"};

	cout << solve(graph, n,m) << endl;

}