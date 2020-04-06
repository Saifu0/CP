#include<bits/stdc++.h>
using namespace std;

#define deb(x) cout << #x << " " << x << endl;
#define fo(i,n) for(int i=0;i<n;i++)
#define Fo(i,k,n) for(int i=k,i<n;i++)
#define vi vector<int>
#define ii pair<int,int>
#define vii vector<ii>
#define ll long long
#define pb push_back
#define endl "\n"
#define mp map<int,int>

int board[11][11];

bool isPossible(int n, int row, int col){
	for(int i=row-1;i>=0;i--){
		if(board[i][col] == 1){
			return false;
		}
	}
	
	for(int i=row-1,j=col-1;i>=0,j>=0;i--,j--){
		if(board[i][j] == 1) return false;
	}
	
	for(int i=row,j=col+1;i>=0,j<n;i--,j++){
		if(board[i][j]) return false;
	}
	
	return true;
}

void nqueenhelp(int n, int row){
	if(row == n){
		fo(i,n)
			fo(j,n)
				cout << board[i][j] << " ";
		cout << endl;
		return;
	}
	
	fo(i,n){
			if(isPossible(n,row,i)){
				board[row][i] = 1;
				nqueenhelp(n,row+1);
				board[row][i] = 0;
			}
	}
	return;
}

void solve(int n){
	memset(board, 0, 11*11*sizeof(n));
	nqueenhelp(n,0);
}

int main(){
	solve(4);
	
	return 0;
}



