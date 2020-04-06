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
	ll a[n],b[n];
	fo(i,n) cin >> a[i];
	fo(i,n) cin >> b[i];
	
	
	int cnt=0;
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			if((a[i]+a[j]) > (b[i]+b[j])){
				cnt++;
			}
		}
	}
	
	cout << cnt << endl;
	
	return 0;
}
