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
		int x,y,x1,y1,x2,y2; cin >> x >> y >> x1 >> y1 >> x2 >> y2 ;

		while(true){
			if(a>0 && x>x1) a--,x--;
			//if(a>0 && x<x2) a--,x--;
			else if(d>0 && y<y2) d--,y++;
			//if(b>0 && y>x2) b--,y++;
			else if(c>0 && y>y1) c--,y--;
			else if(b>0 && x<x2) b--,x++;
			else break;

		}

		if(a!=0 || b!=0 || c!=0 || d != 0) cout << "No" << endl;
		else cout << "Yes" <<endl;


	}
	return 0;
} 

// exactly a steps left: from (u,v) to (u−1,v);
// exactly b steps right: from (u,v) to (u+1,v);
// exactly c steps down: from (u,v) to (u,v−1);
// exactly d steps up: from (u,v) to (u,v+1).