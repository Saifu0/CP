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

vector<int> v[100005];
int a[100005];

int main(){
	int n;
	cin >> n;
	
	Fo(i,1,n){
		int f,s;
		cin >> f >> s;
		v[f].pb(i);
		v[s].pb(i);
		a[i] = -1;
	}
	
	ii m(0,0);
	fo(i,n+1) m = max(m,make_pair((int)v[i].size(),i));
	int cur=0;
	for(int i: v[m.second]) a[i] = cur++;
	
	Fo(i,1,n){
		if(a[i]==-1) a[i]=cur++;
		cout << a[i] << endl;
	}
	
	return 0;
}
