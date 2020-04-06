#include<bits/stdc++.h>
using namespace std;

#define sc(x) scanf("%d",&x)
#define pf(c) scanf("%d",x);
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

const int N = 123456;
int wt[N];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int t;
	cin >> t;
	int start=1;
	while(t--){
		int n,m;
		cin >> n >> m;
		fo(i,n){
			cin >> wt[i];
		}
		sort(wt,wt+n);
		int ans = 0;
		ll sum=0;
		fo(i,n){
			if(sum+wt[i] > m){
				break;
			}else{
				ans++;
				sum += wt[i];
			}
		}
		cout << "Case #" << start++ << ": " << ans << endl;
	}
	
	return 0;
}
