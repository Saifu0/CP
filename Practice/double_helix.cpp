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
	while(n != 0){
		int s1=1,s2=1;
		int*a1 = new int[n];
		int pref[n+1];


		fo(i,n){
			cin >> a1[i];
		}

		pref[0] = 0;
		pref[1] = a1[0];

		for(int i=2;i<=n;i++)
			pref[i] = pref[i-1] + a1[i-1];

		int m;
		cin >> m;
		
		int cref[m+1];
		int*a2 = new int[m];

		fo(i,m){
			cin >> a2[i];

		}

		cref[0] = 0;
		cref[1] = a2[0];

		for(int i=2;i<=m;i++)
			cref[i] = cref[i-1] + a2[i-1];


		int ans=0;
		fo(i,m){
			if(binary_search(a1,a1+n,a2[i])){
				int index = lower_bound(a1,a1+n,a2[i]) - a1;
				int ans1 = pref[index+1] - pref[s1-1];
				int ans2 = cref[i+1] - cref[s2-1];
				ans += max(ans1,ans2);
				s1 = index+2;
				s2 = i+2;
			}
		}

		int x = pref[n] - pref[s1-1];
		int y = cref[m] - cref[s2-1];

		ans += max(x,y);

		cout << ans << endl;
		

		cin >> n;
	}
	
	return 0;
}


