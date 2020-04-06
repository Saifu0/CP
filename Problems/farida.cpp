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

ll solve(ll*arr, ll n){
	if(n<=0) return 0;

	int ans1 = arr[n-1] + solve(arr,n-2);
	int ans2 = solve(arr,n-1);

	int ans = max(ans1,ans2);

	return ans;
}

int main(){
	int t;
	cin >> t;
	int temp = t;
	while(t--) {
	    ll n;
	    cin >> n;
	    ll*arr = new ll[n];
	    for(ll i=0;i<n;i++)
	    	cin >> arr[i];

	    // ll incl = arr[0];
	    // ll excl = 0;
	    // ll excl_new;

	    // for(ll i =1;i<n;i++){
	    // 	excl_new = max(excl,incl);
	    // 	incl = excl + arr[i];
	    // 	excl = excl_new;
	    // }
	    // cout << "Case " <<  temp-t << ": " << max(excl,incl) << endl; 

	    int ans = solve(arr,n);
	    cout << "Case 1: " << ans << endl;
	}
	
	return 0;
}


