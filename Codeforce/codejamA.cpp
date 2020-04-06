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

int main(){
	c_p_c();
	int t; cin >> t;
	int start=1;
	while(t--){
		int n; cin >> n;
		int mat[n][n];
		int trace = 0;
		fo(i,n) fo(j,n){
			cin >> mat[i][j];
			if(i==j) trace += mat[i][j];
		}

		int r=0,c=0;
		fo(i,n){
			set<int> a;
			fo(j,n){
				if(a.count(mat[i][j]) >0){
					c += 1;
					break;
				}
				a.insert(mat[i][j]);
			}
		}

		for(int i=0;i<n;i++){
			set<int> a;
			for(int j=0;j<n;j++){
				if(a.count(mat[j][i])>0){
					r += 1;
					break;
				}
				a.insert(mat[j][i]);
			}
		}

		cout << "Case #" << start++ << ": " << trace << " " << c << " " << r << endl;

	}

	return 0;
} 