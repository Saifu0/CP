#include<bits/stdc++.h>
using namespace std;

#define sc(x) scanf("%d",&x)
#define pf(c) scanf("%d",x);
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
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int t;
	cin >> t;
	int start=1;
	while(t--){
		int n,k;
		cin >> n >> k;
		vi v(n);
		fo(i,n){
			cin >> v[i];
		}
		//sort(v.begin(),v.end());
		
		
		
		
		while(k--){
			int cur = INT_MIN;
			int f,s;
			for(int i=0;i<v.size()-1;i++){
				if(cur  < (v[i+1]-v[i])){
					cur = v[i+1]-v[i];
					f = i+1;
					s = i;
				}
			}
			// cout << (v[f]+v[s])/2 << " ";
			v.pb((v[f]+v[s])/2);
			sort(v.begin(),v.end());
			//cout << cur << " ";
		}
		
		int cur = INT_MIN;
		
		for(int i=0;i<v.size()-1;i++){
				if(cur < v[i+1]-v[i]) {cur = v[i+1]-v[i];}
		}
		cout << "Case #" << start++ << ": " << cur << endl;
		
	}
	
	return 0;
}
