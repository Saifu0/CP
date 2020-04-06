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

struct Node {
	int f,s;
};

bool compare(Node x, Node y){
	return x.f < y.f;
}

int main(){
	int n,d;
	cin >> n >> d;
	Node a[n];
	fo(i,n){
	 	cin >> a[i].f >> a[i].s;
		
	}
	
	sort(a,a+n,compare);
	ll ans=0;
	ll mx=0;
	
	int r=0,l=0;
	for(;l<n;++l){
		while(r<n &&  a[r].f < d + a[l].f ){ ans += a[r].s; ++r;}
		mx = max(mx,ans);
		ans -= a[l].s;
	}
	
	cout << mx << endl;
	
	
	return 0;
}
