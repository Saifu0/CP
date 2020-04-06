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

const int mxn = 42;
string s[mxn];
int dp[mxn][mxn][mxn][mxn], pref[mxn][mxn][mxn][mxn];

int main(){
	c_p_c();
	int n,m,q; cin >> n >> m >> q;
	fo(i,n) cin >> s[i];

	fo(x,n){
		fo(y,m){
			Fo(i,x,n){
				Fo(j,y,m){
					dp[x][y][i][j] = 1 - (s[i][j]-'0');
					if(x<i && dp[x][y][i-1][j]==0) dp[x][y][i][j] = 0;
					if(y<i && dp[x][y][i][j-1]==0) dp[x][y][i][j] = 0;
				}
			}
			fo(i,n){
				fo(j,m){
					pref[x][y][i+1][j+1] = pref[x][y][i+1][j] + pref[x][y][i][j+1] + dp[x][y][i][j] -pref[x][y][i][j];
				}
			}
		}
	}

	for (int i = 0; i < q; i++)
    {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        a--, b--, c--, d--;
        int ans = 0;
        for (int x = a; x <= c; x++)
            for (int y = b; y <= d; y++)
                ans += pref[x][y][c + 1][d + 1];
        cout << ans << "\n";
    }

	return 0;
}