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

struct mode {
	int x,y;
} m[110];

bool cmp(mode a, mode b){
	return a.x < b.x;
}

int main(){
	c_p_c();
	int n; cin >> n;
	int neg=0,pos=0;

	ll tot = 0;
	fo(i,n){
		cin >> m[i].x >> m[i].y;
		if(m[i].x<0) neg++;
		else pos++;
		tot += m[i].y;
	}

	if(abs(pos-neg) <= 1){
		cout << tot << endl;
		return 0;
	}

	int diff = pos-neg;

	sort(m,m+n,cmp);

	if(diff>0){
		int l=0,r=0;
		fo(i,n){
			if(m[i].x >0){
				r=i;
				break;
			}
		}
		l = r-1;
		if(l==-1){
			cout << m[0].y << endl;
			return 0;
		}
		int cnt=0;
		tot = 0;
		while(cnt!=neg){
			tot += m[l].y;
			tot += m[r].y;
			l--; r++;
		}
		tot += m[r].y;
	}else{
		int l=-1,r=-1;
		fo(i,n){
			if(m[i].x >0){
				r=i;
				break;
			}
		}
		if(r==-1){
			cout << m[0].y << endl;
			return 0;
		}
		l  = r-1;
		int cnt=0;
		tot = 0;
		while(cnt!=pos){
			tot += m[l].y;
			tot += m[r].y;
			l--; r++;
		}
		tot += m[l].y;
	}

	cout << tot << endl;




	return 0;
}