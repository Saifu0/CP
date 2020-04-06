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

struct no{
	int d,in;
};

int main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		no a[n];
		Fo(i,1,n+1){ cin >> a[i].d; a[i].in = i; }
		Fo(i,1,n+1){
			int cnt=1;
			int idy=a[i].d;
			int temp = a[idy].d;
			while(a[i].d != temp){
				idy = temp;
				temp = a[idy].d;
				cnt++;
			}
			cout << cnt << " ";
		}
		cout << endl;
		
	}
	return 0;
}
