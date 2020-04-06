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
	int t; cin >> t;
	while(t--){
		int a,b,c,d; cin >> a >> b >> c >> d;
		int x,y,x1,y1,x2,y2; cin >> x >> y >> x1 >> y1 >> x2 >> y2;
		x += -a + b;
		y += -c + d;
		if(x>=x1&&x<=x2&&(x1<x2 || a+b==0)&&y>=y1&&y<=y2&&(y1<y2||c+d==0)) cout << "Yes\n";
		else cout << "No\n";
	}

	return 0;
}