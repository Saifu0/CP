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
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		ll*arr = new ll[n];
		int q;
		cin >> q;
		bitset<27> r;
		int even=0,odd=0;
		fo(i,n){
			int data;
			cin >> data;
			r = data;
			if(r.count()%2==0) even++;
			else odd++;
		}
		
		while(q--){
			int p;
			cin >> p;
			bitset<20> ans;
			ans=p;
			if(ans.count()%2==0){
				cout << even << " " << odd << endl;
			}else{
				cout << odd << " " << even << endl;
			}
		}
		delete[] arr;
	}
	
	return 0;
}


