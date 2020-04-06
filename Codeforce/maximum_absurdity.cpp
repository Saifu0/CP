// #include<bits/stdc++.h>
// using namespace std;

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
// #define F first
// #define S second
// #define sz(v) (int)v.size()
// #define mod 1000000007

// void c_p_c()
// {
// 	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
// #ifndef ONLINE_JUDGE
// 	freopen("input.txt", "r", stdin);
// 	freopen("output.txt", "w", stdout);
// #endif
// }

// const int mxn = 6e6;
// int n,k;
// int x[mxn];

// int solve(int a, int b, ll **dp){
// 	if((b+k-1)>n) return 0;
// 	if((a+k)>b) return 0;

// 	if(dp[a][b]!=-1){
// 		return dp[a][b];
// 	}

// 	int ans1 = 0;
// 	for(int i=a;i<a+k;i++){
// 		ans1 += x[i];
// 	}
// 	int ans2 = 0;
// 	for(int i=b;i<b+k;i++){
// 		ans2 += x[i];
// 	}
// 	int ans = ans1 + ans2;

// 	ans = max({ans,solve(a+1,b,dp),solve(a,b+1,dp),solve(a+1,b+1,dp)});

// 	dp[a][b] = ans;
// 	return ans;
// }

// int main(){
// 	c_p_c();
// 	cin >> n >> k;
// 	fo(i,n) cin >> x[i];

// 	ll**dp = new ll*[n+1];
// 	fo(i,n+1){
// 		dp[i] = new ll[n+1];
// 		fo(j,n+1){
// 			dp[i][j] = -1;
// 		}
// 	}

// 	int ans =  solve(0,k,dp);

// 	Fo(i,0,n){
// 		Fo(j,0,n){
// 			// if(dp[i][j]==ans){
// 			// 	cout << i << " " << j << endl;
// 			// 	return 0;
// 			// } 
// 			cout << dp[i][j] << " ";
// 		}
// 		cout << endl;
// 	}

// 	return 0;
// }

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

const int mxn = 6e6;
int n,k;
ll a[mxn];

ll pref[mxn];

ll get_sum(int l,int r){
	return (l==0) ? pref[r] : pref[r] - pref[l-1];
}

int main(){
	c_p_c();
	cin >> n >> k;
	fo(i,n) cin >> a[i];

	pref[0] = a[0];
	Fo(i,1,n) pref[i] = pref[i-1] + a[i];

	pair<int,int> ans = make_pair(n-2*k,n-k);
	ll mn = get_sum(n-2*k,n-k-1) + get_sum(n-k,n-1);
	pair<int,ll> suff = make_pair(n-k,get_sum(n-k,n-1));

	for(int i=n-2*k-1;i>=0;i--){
		ll cur = get_sum(i+k,i+2*k-1);
		if(cur>=suff.S){
			suff = make_pair(i+k,cur);
		}
		cur = get_sum(i,i+k-1) + suff.S;
		if(cur>=mn){
			mn = cur;
			ans = make_pair(i,suff.F);
		}
	}

	cout << ans.F +1<< " " << ans.S +1<< endl;




	return 0;
}