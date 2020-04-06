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
	int n;
	cin >> n;
	
	vi deg(n),sop(n),a(n);	

	Fo(i,1,n){
		cin >> a[i];
		--a[i];
		deg[a[i]]++;
	}

	fo(i,n){
		if(deg[i]==0) sop[a[i]]++;
	}

	fo(i,n){
		if(deg[i]>0 && sop[i]<3){
			puts("No"); return 0;
		}
	}

	puts("Yes");



	return 0;
}