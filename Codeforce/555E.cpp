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
	int n;
	cin >> n;
	vector<int> a(n);
	multiset<int> b;

	fo(i,n) cin >> a[i];
	fo(i,n){
		int x;
		cin >> x;
		b.insert(x);
	}


	fo(i,n){
		auto it = b.lower_bound(n-a[i]);
		if(it == b.end()) it=b.begin();
		cout << (a[i] + *it)%n << " ";
		b.erase(it);
	}

	cout << endl;
	
	return 0;
}


