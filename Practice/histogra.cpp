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
	ll n;
	cin >> n;
	while(n!=0){
		ll*arr = new ll[n];
		fo(i,n) cin >> arr[i];

		ll max = INT_MIN;

		stack<ll> s;
		ll i=0;
		while(i<n){
			if(s.empty() || arr[s.top()] <= arr[i]){
				s.push(i++);
			}

			else{
				ll tp = s.top();
				s.pop();

				ll area = arr[tp]*(s.empty() ? i : (i-s.top()- 1));
				if(max < area)
					max = area;
			}
		}

		while(!s.empty()){
			ll tp = s.top();
				s.pop();

				ll area = arr[tp]*(s.empty() ? i : (i-s.top()- 1));
				if(max < area)
					max = area;
		}

		cout << max << endl;
		cin >> n;
	}
	
	return 0;
}


