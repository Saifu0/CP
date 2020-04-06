#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	int t;
	cin >> t;
	while(t--){
		ll n,k1,k2,k3,i,x,y,ans1,ans2,ans3;
		cin >> n >> k1 >> k2 >> k3;
		ll a[n];
		for(int i=0;i<n;i++) cin >> a[i];
		priority_queue<ll , vector<ll>, greater<ll>> q;
		ll pref[n]; pref[0] = a[0];
		for(i=1;i<n;i++) pref[i] = pref[i-1] + a[i];
		for(i=0;i<n;i++){
			if(q.size() < k3) q.push(pref[i]);
			else if(q.size() == k3 && pref[i] > q.top()){
				q.pop();
				q.push(pref[i]);
			}
			for(int j=0;j<i;j++){
				ll temp = pref[i] - pref[j];
				if(q.size() < k3) q.push(temp);
				else if( q.size() == k3 && temp > q.top()){
					q.pop();
					q.push(temp);
				}
			}
		}
		ans3 = q.top();
		for(i=0;i<k3-k2;i++) q.pop();
		ans2 = q.top();
		for(i=0;i<k2-k1;i++) q.pop();
		ans1 = q.top();

		cout << ans1 << " " << ans2 << " " << ans3 ;
		while(!q.empty()) q.pop();
		cout << "\n";
	}
}
