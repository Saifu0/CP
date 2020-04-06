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
	int t;
	cin >>t;
	while(t--){
		int n,k;
		cin >> n >> k;
		vector<ll> v(n);
		priority_queue<ll> pq;
		for(int i=0;i<n;i++){
			cin >> v[i];
			pq.push(v[i]);
		}
		ll p = 	log10(10000000000000000)/log10(k);
		p++;
		for(int i=p;i>=0;i--){
			ll t = pq.top();
			

			if(t==0) break;

			if(t >= pow(k,i)){
				pq.pop();
				t -= (ll)pow(k,i);
				pq.push(t);
			}
		}

		if(pq.top() == 0 ) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	
	return 0;
}


