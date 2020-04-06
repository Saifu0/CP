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
		int n;
		cin >> n;
		int a[n];
		fo(i,n) cin >>a[i];
		
		bool flag=0;
		for(int i=0;i<n;i++){
			for(int j=n-1;j>i;j--){
				if(a[i]==a[j] && (j-i+1)>=3){
					flag=1;
					break;
				}
			}
		}
		if(flag==1) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	
	return 0;
}
