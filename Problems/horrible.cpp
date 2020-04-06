#include<bits/stdc++.h>
using namespace std;

const int N=100005;
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


long long int lazy[4*N];
long long int seg[4*N];

void build(int start, int end, int index){
	if(start>end) return;
	if(start==end){
		seg[index] = 0;
		return;
	}
	int mid =start+end>>1;
	build(start,mid,2*index+1);
	build(mid+1,end,2*index+2);

	seg[index] = seg[2*index+1] + seg[2*index+2];
}

void update(int start, int end, int l, int r, int index, ll data){
	if(start > end) return;

	if(lazy[index]!=0){
		seg[index] += lazy[index];
		if(start != end){
			lazy[2*index+1] += lazy[index];
			lazy[2*index+2] += lazy[index];
		}
		lazy[index] = 0;
	}

	if(l > end || start > r) return;

	if(l<=start && end <= r){
		seg[index] += data;
		if(start!=end){
			lazy[2*index+1] += data;
			lazy[2*index+2] += data;
		}
		return;
	}

	int mid = (start+end)/2;
	update(start,mid,l,r,2*index+1,data);
	update(mid+1,end,l,r,2*index+2,data);

	seg[index] = seg[2*index+1] + seg[2*index+2];
}

ll query(int start, int end, int l, int r, int index){
	if(lazy[index]!=0){
		seg[index] += lazy[index];
		if(start != end){
			lazy[2*index+1] += lazy[index];
			lazy[2*index+2] += lazy[index];
		}
		lazy[index] = 0;
	}

	if(l > end || start > r) return 0;

	if(l<=start && end <= r){
		return seg[index];
	}
	int mid = start+end>>1;
	return query(start,mid,l,r,2*index+1) + query(mid+1,end,l,r,2*index+2);
}

int main(){
	int t;
	cin >> t;
	while(t--){
		memset(lazy,0,sizeof(lazy));
		memset(seg,0,sizeof(seg));
		int n,q;
		cin >> n >> q;

		build(0,n-1,0);

		while(q--){
			int c;
			cin >> c;
			if(c==0){
				int l,r;
				ll data;
				cin >> l >> r >> data ;
				update(0,n-1,l-1,r-1,0,data);
			}else{
				int l,r;
				cin >> l >> r;
				cout << query(0,n-1,l-1,r-1,0) << endl;
			}
		}
	}
	
	return 0;
}


