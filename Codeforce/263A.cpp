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
	int n;
	cin >> n;
	vi v(n);
	vector<ll> sum(n+1,0);
	
	
	fo(i,n){
		cin >> v[i];
	}
	
	sort(v.begin(),v.end());
	for(int i=0;i<n;i++){
		sum[i+1] = sum[i] + v[i];
	}
	
	unsigned ll ans=sum[n];
	
	fo(i,n-1){
		ans += sum[n]-sum[i];
	}
	
	cout << ans << endl;
	
	return 0;
}
