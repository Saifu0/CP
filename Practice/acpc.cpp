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
		int *a = new int[n];
		fo(i,n) cin >> a[i];

		int m;
		cin >> m;
		int*b = new int[m];
		fo(i,m) cin >> b[i];

		sort(a,a+n);
		sort(b,b+m);

		int min = INT_MAX;

		int i = 0,j=0;;
		while( i<n && j <m){
			if(abs(a[i] - b[j]) < min)
				min = abs(a[i] - b[j]);

			if(a[i] < b[j])
				i++;
			else
				j++;
		}

		cout << min << endl;
	}
	
	return 0;
}


