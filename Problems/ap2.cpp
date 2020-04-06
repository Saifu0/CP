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
		ll first,last,sum;
		cin >> first >> last >> sum;
		ll n = (2*sum)/(first+last);

		ll d = (last-first)/(n-5);
		ll a = first - 2*d;
		
		Fo(i,1,n+1){
			cout << a << " ";
			a = a+d;
		}
		cout << endl;
	}
	
	return 0;
}


