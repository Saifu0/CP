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
	cin >> t;
	while(t--){
		ll a ,b;
		cin >> a >> b;

		if(b==0){
			cout << 1 << endl;
			continue;
		}
		ll ans = a;
		b = b%4;
		while(b>0){
			ans  = a%10;
			a = a*a;
			b--;

		} 
		cout << ans << endl;
	}
	
	return 0;
}



