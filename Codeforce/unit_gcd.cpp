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
	while(t--){
		int n; cin >> n;
		
		if(n==1) cout << 1 << endl << 1 << " " << 1 << endl;
		else if(n==2) cout << 1 << endl << 2 << " " << 1 << " " << 2 << endl;
		else if(n==3) cout << 1 << endl << 3 << " " << 1 << " " << 2 << " " << 3 << endl;
		else{
			int i = 1;
			cout << 1 + (n-2)/2 << endl;
			cout << 3 << " " << i++ << " " << i++ << " " << i++ << endl;
			while(i<=n){
				if((i+1)<=n) cout << 2 << " ";
				else cout << 1 << " ";
				cout <<  i++ << " ";
				if(i<=n){
					cout << i++ << endl;
				}else{
					cout << endl;
				}
			}
		}
	}

	return 0;
}