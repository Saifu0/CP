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

const int mxn = 1234;
int a[mxn];

int main(){
	c_p_c();
	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		fo(i,n) cin >> a[i];
		
		int p[n];
		int start=1;
		p[0] = start;
		Fo(i,1,n){
			if(__gcd(a[i],a[i-1])>1){
				p[i] = p[i-1];
			}else{
				int flag = 1;
				for(int j=i-1;j>=0;j--){
					if(__gcd(a[i],a[j])>1){
						p[i] = p[j];
						flag=0;
						break;
					}
				}
				if(flag==1){
					++start;
					p[i] = start;
				}
			}
		}
		cout << start << endl;
		fo(i,n) cout << p[i] << " ";
		cout << endl;
	}

	return 0;
}