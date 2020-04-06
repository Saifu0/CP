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
		int n,m;
		cin >> n >> m;
		mp r;
		int*ty = new int[n];
		int*p = new int[n];
		for(int i=0;i<n;i++){
			int type;
			cin >> type;
			ty[i] = type;
		}
		for(int i=0;i<n;i++){
			cin >> p[i];
		}
		for(int i=0;i<n;i++){
			r[ty[i]] += p[i];
		}
		int min = INT_MAX;

		for(auto it=r.begin();it!=r.end();it++){
			if(it->second < min)
				min = it->second;
		}
		cout << min << endl;
		
	}
	
	return 0;
}


