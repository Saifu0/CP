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
#define F first
#define S second
#define sz(v) (int)v.size()
#define mod 1000000007

void c_p_c()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}
const int mxn = 500;
char mat[500][500];

int solve(int r, int c, int n, int m, int p, int cnt){
	if(p==cnt) return 0;
	if(r==n && c==m) return 0;

	int ans = 0;
	if(r==n && r%2==1 && c<n){
		if(mat[r][c+1]=='P') ans += 1 + min(ans,solve(r,c+1,n,m,p+1,cnt));
		else ans +=  1 + min(solve(r,c+1,n,m,p,cnt),ans);
	}
	if(r==n && r%2==0 && c>1){
		if(mat[r][c-1]=='P') ans +=  1 + min(solve(r,c-1,n,m,p+1,cnt),ans);
		else ans +=  1 + min(solve(r,c-1,n,m,p,cnt),ans);
	}
	if(c==m || c==1){
		if(mat[r+1][c]=='P') ans +=  1 + min(solve(r+1,c,n,m,p+1,cnt),ans);
		else ans += 1 + min(solve(r+1,c,n,m,p,cnt),ans);
	}
	if(r%2==1){
		if(mat[r][c+1]=='P') ans += 1 + min(ans,solve(r,c+1,n,m,p+1,cnt));
		else ans +=  1 + min(solve(r,c+1,n,m,p,cnt),ans);
	}
	if(r%2==0){
		if(mat[r][c-1]=='P') ans +=  1 + min(solve(r,c-1,n,m,p+1,cnt),ans);
		else ans +=  1 + min(solve(r,c-1,n,m,p,cnt),ans);
	}
	if(mat[r+1][c]=='P') ans +=  1 + min(solve(r+1,c,n,m,p+1,cnt),ans);
	else ans += 1 + min(solve(r+1,c,n,m,p,cnt),ans);

	return ans;
}

int main(){
	c_p_c();
	int t; cin >> t;
	while(t--){
		int n,m; cin >> n >> m;
		int cnt=0;
		Fo(i,1,n+1){
			Fo(j,1,m+1){
				cin >> mat[i][j];
				if(mat[i][j]=='P') cnt++;
			}
		}
		//cout << cnt << endl;
		cout << solve(1,1,n+1,m+1,0,cnt) << endl;
	}

	return 0;
}