#include<bits/stdc++.h>
using namespace std;

// #define vi vector<int>
// #define fo(i,n) for(int i=0;i<n;i++)
// #define Fo(i,k,n) for(int i=k;i<n;i++)
// #define rep(n) for(int i=n-1;i>=0;i--)
// #define ii pair<int,int>
// #define m map<int,int>
// #define pb push_back
// #define ll long long

int mat[105][105];

int main(){
  int n,m;
  cin >> n >> m;
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      scanf("%d",&mat[i][j] );
    }
  }

  int dp[n][m];

  for(int i=0;i<m;i++)
    dp[0][i] = mat[0][i];

  for(int i=1;i<n;i++){
    for(int j=0;j<m;j++){
      int l = (j>0)?dp[i-1][j-1] : INT_MAX;
      int mid = dp[i-1][j];
      int r = (j<m-1)?dp[i-1][j+1] : INT_MAX;
      dp[i][j] = mat[i][j] + min(l,min(mid,r));
    }
  }

  int min = INT_MAX;
  for(int i=0;i<m;i++){
    if(dp[n-1][i] < min)
     min = dp[n-1][i];
  }

  cout << min << endl;


  return 0;
}
