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
#define pw(x) (1ll<<(x))

void c_p_c()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}

const int mxn = 2e6;
int a[mxn];
int ss[mxn],s[mxn],ans[mxn];
int n,m;
int x[mxn],y[mxn],p[mxn];
int tree[4*mxn];

void build(int i, int l, int r){
	if(l+1==r){
		tree[i] = ans[l];
		return;
	}
	int mid = (l+r)>>1;
	build(2*i,l,mid);
	build(2*i+1,mid,r);

	tree[i] = tree[2*i] & tree[2*i+1];
}

int query(int i, int l, int r, int L, int R){
	if(l==L && r==R) return tree[i];
	int mid = (L+R)>>1;

	int ans = (1ll<<30)-1;

	if(l<mid){
		ans &= query(2*i,l,min(r,mid),L,mid);
	}
	if(r>mid){
		ans &= query(2*i+1,max(l,mid),r,mid,R);
	}

	return ans;
}

int main(){
	c_p_c();

	cin >> n >> m;
	fo(i,m){
		cin >> x[i] >> y[i] >> p[i];
		--x[i];
	}

	fo(t,31){
		fo(i,n) s[i] = 0;
		fo(i,m){
			if(pw(t)&p[i]){
				s[x[i]]++;
				s[y[i]]--;
			}
		}

			
		// fo(i,n) 
		// cout <<s[i] << " ";

		fo(i,n){

			if(i>0) s[i] += s[i-1];
			if(s[i]>0){
				ans[i] |= (1<<t);
			}
		}
		//-cout << endl;
	}

	build(1,0,n);

	fo(i,m){
		if(query(1,x[i],y[i],0,n) != p[i]){
			puts("NO");
			return 0;
		}
	}


	//puts("YES");
	cout << "YES\n";
	fo(i,n){
		cout << ans[i] << " ";
	}
	//puts("");


	return 0;
}