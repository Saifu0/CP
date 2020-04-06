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
	mp m;
	while(t--){
		int n;
		cin >> n;
		m[n]++;
	}
	for(auto it=m.begin();it!=m.end();it++){
		if(it->second == 1){
			cout << it->first << endl;
			break;
		}
	}
	
	return 0;
}


