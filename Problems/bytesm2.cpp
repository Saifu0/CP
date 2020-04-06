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


int solve(int**matrix, int r, int c, int currR, int currC, int**dp){

	if(currR >= r || currC >= c || currC < 0) return 0;

	if(dp[currR][currC] != -1)
		return dp[currR][currC];

	int ans = matrix[currR][currC] + max(solve(matrix,r,c,currR+1,currC,dp), max(solve(matrix,r,c,currR+1,currC+1,dp),solve(matrix,r,c,currR+1,currC-1,dp)));

	dp[currR][currC] = ans;

	return ans;
}

int solve(int**matrix, int r, int c){
	int ma = -1;
	Fo(i,1,r){
		ma = -1;
		fo(j,c){
			if(j>0 && j<c-1)
				matrix[i][j] = max(matrix[i][j] + matrix[i-1][j], max(matrix[i][j] + matrix[i-1][j-1], matrix[i][j] + matrix[i-1][j+1]));
			else if(j>0)
				matrix[i][j] = max(matrix[i][j] + matrix[i-1][j] , matrix[i][j] + matrix[i-1][j-1]);
			else if(j<c-1)
				matrix[i][j] = max(matrix[i][j] + matrix[i-1][j], matrix[i][j] + matrix[i-1][j+1]);
			ma = max(matrix[i][j], ma);
		}

	}
	return ma;
}

int main(){
	int t;
	cin >> t;
	while(t--){
		int r,c;
		cin >> r >> c;
		int**matrix = new int*[r];
		fo(i,r){
			matrix[i] = new int[c];
			fo(j,c){
				cin >> matrix[i][j];
			}
		}

		int**dp = new int*[r+1];
		fo(i,r+1){
			dp[i] = new int[c+1];
			fo(j,c+1){
				dp[i][j] = -1;
			}
		}
		int max= INT_MIN, index;
		fo(i,c){
			if(matrix[0][i] > max){
				max = matrix[0][i];
				index = i;
			}
		}
		// cout <<  solve(matrix,r,c,0,index,dp) << endl;
		cout << solve(matrix,r,c) << endl;

	}
	
	return 0;
}


