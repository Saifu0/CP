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

int solve(int** matrix, int n){
	int**dp = new int*[n+1];
	fo(i,n){
		dp[i] = new int[n+1];
		fo(j,n){
			dp[i][j] = 0;
		}
	}

	dp[0][0] = matrix[0][0];

	for(int i=1;i<n;i++)
		dp[i][0] =dp[i-1][0] +  matrix[i][0];

	Fo(i,1,n)
		dp[0][i]  = dp[0][i-1] +  matrix[0][i];

	for(int i=1;i<n;i++){
		for(int j=1;j<n;j++){
			dp[i][j] = matrix[i][j] + min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1]));
		}
	}

	return dp[n-1][n-1];
}

int main(){
	int n;
	cin >> n;
	int** matrix = new int*[n];

	fo(i,n){
		matrix[i] = new int[n];
		fo(j,n){
			cin >> matrix[i][j];
		}
	}

	cout << solve(matrix,n) << endl;
	
	return 0;
}


