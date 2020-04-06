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
		ll n;
		cin >> n;

		ll a = sqrt(n),i=0,j=0;
		while(a>0){
			if(i*i > n){
				cout << "No" << endl;
				break;
			}
			else if(a*a + i*i == n){
				cout << "Yes" << endl;
				break;
			}
			else if(a*a + i*i < n){
				i++;
			}else{
				a--;
			}
		}
	}
	

	
	return 0;
}


