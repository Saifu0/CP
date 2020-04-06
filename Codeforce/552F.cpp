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

int main(){
	int n,m,k;
	cin >> n >> m >> k;
	vector<int> a(n);
	for(int i=0;i<n;i++) cin >> a[i];

	sort(a.begin(),a.end());
	a.resize(k);
	reverse(a.begin(),a.end());

	vector<int> order(k+1);
	fo(i,m){
		int x,y;
		cin >> x >> y;
		if(x<=k)
			order[x] = max(order[x],y);
	}

	vector<int> pref(k+1);
	fo(i,k){
		pref[i+1] = pref[i] + a[i];
	}

	vector<int> dp(k+1,INT_MAX);
	dp[0] = 0;
	for(int i=0;i<k;i++){
		dp[i+1] = min(dp[i+1],dp[i] + a[i]);
		for(int j=1;j<=k;j++){
			if(order[j] ==0) continue;
			if(i+j > k ) break;

			dp[i+j] = min(dp[i+j], dp[i] + pref[i+j-order[j]] - pref[i]);
		}
	}

	cout << dp[k] << endl;
	
	return 0;
}


