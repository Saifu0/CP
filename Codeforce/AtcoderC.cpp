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
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	float l;
	cin >> l;
	
	
	float ans = 0;
	
	float len = l/3;
	l -= len;
	
	float b = l /2;
	
	//cout << b << endl;
	
	float h = l - b;
	
	ans = len*b*h;
	
	printf("%0.12f\n",ans);
	
	
	return 0;
}
