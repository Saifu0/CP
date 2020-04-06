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
		int n,k;
		cin >> n >> k;
		int*arr = new int[n];
		fo(i,n)
			cin >> arr[i];

		if(k==1){
			cout << 0 << endl;
			continue;
		}

		sort(arr,arr+n);

		int start=0, min = INT_MAX;

		for(int i=k-1;i<n;i++){
			if(min > abs(arr[i]-arr[start])){
				min = abs(arr[i]-arr[start]);
			}
			start++;
		}

		cout << min << endl;
		delete[]arr;
 	}
	
	return 0;
}


