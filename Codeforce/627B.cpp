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
		int n;
		cin >> n;
		vector<int> v(n);
		fo(i,n) cin >> v[i];
		if(n==1){
			cout << v[0] << endl;
			continue;
		}
		sort(v.rbegin(),v.rend());
		fo(i,n) cout << v[i] << " ";
		cout << endl;
	}
	
	return 0;
}


