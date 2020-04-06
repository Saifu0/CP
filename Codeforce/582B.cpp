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



int main(){
	int t;
	cin >> t;
	
	while(t--){
		int n; cin >>n;
		int a[n];
		fo(i,n) cin >> a[i];
		int mn=a[n-1];
		int ans=0;
		for(int i=n-2;i>=0;i--){
			if(a[i] <= mn){
				mn = a[i];
			}else{
				ans++;
			}
		}
		
		cout << ans << endl;
	}
	
	
	
	return 0;
}
