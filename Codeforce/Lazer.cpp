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
#define S second
#define F first

const int N = 1e5;
int n,q,a[N],ans[N],ql[N],qr[N],ft[N],qy[N];

void update(int i, int x){
	for(++i; i<n; i+=i&-i)
		ft[i]+=x;
}

int query(int i){
	int r=0;
	for(; i; i-=i&-i)
		r+=ft[i];
	return r;
}

struct event {
	int y,t,i;
	bool operator<(const event &o) const {
		return make_pair(y, t)<make_pair(o.y, o.t);
	}
};

void solve(){
	cin >> n >> q;
	
	fo(i,n) cin >> a[i];
	fo(i,q) cin >> ql[i] >> qr[i] >> qy[i], --ql[i], --qr[i];
	
	vector<event> v;
	fo(i,n-1){
		v.pb({min(a[i],a[i+1]),1,i});
		v.pb({max(a[i],a[i+1]),3,i});
	}
	
	fo(i,q) { v.pb({qy[i],2,i}); }
	
	sort(v.begin(),v.end());
	
	for(event e : v){
		if(e.t==1){
			update(e.i,1);
		}else if(e.t==2){
			ans[e.i] =  query(qr[e.i]) - query(ql[e.i]) ;
		}else{
			update(e.i,-1);
		}
	}
	fo(i,q) cout << ans[i] << endl;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	
	int t;
	cin >> t;
	while(t--) solve();
	
	return 0;
}
