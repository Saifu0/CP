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
	mp m;
	ll flag=1;
	ll count = 0;
	while(n!=1){
		m[n]++;
		if(m[n] > 1){
			flag = 0;
			break;
		}
		ll store = 0;
		while(n!=0){
			ll rem = n%10;
			store += rem*rem;
			n /=10;
		}
		n = store;
		count++;
	}


	if(flag==1)
		cout << count << endl;
	else
		cout << -1 << endl;
	
	return 0;
}


