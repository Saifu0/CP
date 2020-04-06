#include<bits/stdc++.h>
using namespace std;

#define deb(x) cout << #x << " " << x << endl;
#define fo(i,n) for(int i=0;i<n;i++)
#define Fo(i,k,n) for(int i=k;i<n;i++)
#define vi vector<int>
#define ii pair<int,int>
#define vii vector<ii >
#define ll long long
#define pb push_back
#define endl "\n"
#define mp map<int,int>

// bool compare(int a, int b){
// 	return a > b;
// }


int main(){
	int n;
	cin >> n;
	vii v;
	vector<int> arr(n);
	fo(i,n){
		int f,s;
		cin >> f >> s;
		v.pb(ii(f,s));
		arr[i] = i;
	}

	sort(arr.begin(),arr.end(),[&](int i, int j) { v[i].first - v[i].second > v[j].first - v[j].second ; });

	ll ans=0;
	Fo(i,0,n){
		ans += v[arr[i]].first*i + v[arr[i]].second*(n-i-1); 
	}
	cout << ans << endl;
	
	return 0;
}


