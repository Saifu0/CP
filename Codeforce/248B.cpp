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

// const int N = 100000;

int main(){
	int n;
	cin >> n;
	vector<ll> v(n),u(n);
	fo(i,n){
		cin >> v[i];
		u[i] = v[i];
	}
	sort(u.begin(),u.end());
	vector<ll> dp1(n+1,0),dp2(n+1,0);
	
	for(int i=1;i<=n;i++){
		dp1[i] += dp1[i-1] + v[i-1];
		dp2[i] += dp2[i-1] + u[i-1];
	}
	
	int k;
	cin >> k;
	while(k--){
		int t,l,r;
		cin >> t >> l >> r;
		if(t==1){
			cout << dp1[r] - dp1[l-1] << endl;
		}else{
			cout << dp2[r] - dp2[l-1] << endl;
		}
	}
	
	return 0;
}




// #include<bits/stdc++.h>
// using namespace std;
// 
// #define sc(x) scanf("%d",&x)
// #define pf(c) scanf("%d",x);
// #define deb(x) cout << #x << " " << x << endl;
// #define fo(i,n) for(int i=0;i<n;i++)
// #define Fo(i,k,n) for(int i=k;i<n;i++)
// #define vi vector<int>
// #define ii pair<int,int>
// #define vii vector<ii>
// #define ll long long
// #define pb push_back
// #define endl "\n"
// #define mp map<int,int>
// 
// void buildA(int treeA[], vi a, int start, int end, int ind){
	// if(start==end){
		// treeA[ind] = a[start];
		// return;
	// }
	// int mid = (start+end)/2;
	// buildA(treeA,a,start,mid,2*ind);
	// buildA(treeA,a,mid+1,end,2*ind+1);
// 
	// treeA[ind] = treeA[2*ind] + treeA[2*ind+1];
// }
// 
// void buildB(int treeA[], vi a, int start, int end, int ind){
	// if(start==end){
		// treeA[ind] = a[start];
		// return;
	// }
	// int mid = (start+end)/2;
	// buildB(treeA,a,start,mid,2*ind);
	// buildB(treeA,a,mid+1,end,2*ind+1);
// 	
	// treeA[ind] = treeA[2*ind] + treeA[2*ind+1];
// }
// 
// int queryA(int treeA[], int start, int end, int ind, int l, int r){
	// if(l>end || r < start) return 0;
	// if(start >= l && end <= r) return treeA[ind];
// 	
	// int mid = (start+end)/2;
	// int ans1 = queryA(treeA,start,mid,2*ind,l,r);
	// int ans2 = queryA(treeA,mid+1,end,2*ind+1,l,r);
// 	
	// return ans1 + ans2;
// }
// 
// 
// int queryB(int treeA[], int start, int end, int ind, int l, int r){
	// if(l>end || r < start) return 0;
	// if(start >= l && end <= r) return treeA[ind];
// 	
	// int mid = (start+end)/2;
	// int ans1 = queryB(treeA,start,mid,2*ind,l,r);
	// int ans2 = queryB(treeA,mid+1,end,2*ind+1,l,r);
// 	
	// return ans1 + ans2;
// }
// 
// 
// 
// int main(){
	// int n;
	// cin >> n;
	// vi a(n),b(n);
	// fo(i,n){
		// cin >> a[i];
		// b[i] = a[i];
	// }
	// int treeA[4*n];
	// int treeB[4*n];
// 	
	// buildA(treeA,a,0,n-1,1);
	// sort(b.begin(),b.end());
	// buildB(treeB,b,0,n-1,1);
// 	
	// int k;
	// cin >> k;
	// while(k--){
		// int t,l,r;
		// cin >> t >> l >> r;
		// if(t==1){
			// cout << queryA(treeA,0,n-1,1,l-1,r-1) << endl;
		// }else{
			// cout << queryB(treeB,0,n-1,1,l-1,r-1) << endl;
		// }
	// }
// 	
// 	
	// return 0;
// }
// 


