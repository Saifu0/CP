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
	int*arr = new int[n];
	fo(i,n)
		cin >> arr[i];

	vi lhs;
	vi rhs;

	fo(i,n)
		fo(j,n)
			fo(k,n)
				lhs.pb((arr[i]*arr[j]) + arr[k]);


	fo(i,n)
		fo(j,n)
			fo(k,n){
				if(arr[k] == 0) continue;

				rhs.pb((arr[i]+ arr[j])*arr[k]);
			}

	sort(lhs.begin(),lhs.end());
	sort(rhs.begin(),rhs.end());

	int res=0;

	fo(i,lhs.size()){
		int lo = lower_bound(rhs.begin(),rhs.end(),lhs[i])-rhs.begin();
		int hi = upper_bound(rhs.begin(),rhs.end(),lhs[i])-rhs.begin();
		res += (hi-lo);
	}

	cout << res << endl;

	
	return 0;
}


