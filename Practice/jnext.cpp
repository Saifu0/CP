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

int arr[1000000];

int main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		fo(i,n) cin >> arr[i];

		int i;
		for(i=n-2;i>=0;i--){
			if(arr[i] < arr[i+1]){
				break;
			}
		}

		if(i==-1){
			cout << -1 << endl;
			continue;
		}


		int j;
		for(j=i+1;j<n;j++){
			if(arr[j] <= arr[i])
				break;
		}
		swap(arr[i],arr[j-1]);
		sort(arr+i+1,arr+n);

		for(int i=0;i<n;i++){
			cout << arr[i];
		}

		cout << endl;

	}
	
	return 0;
}


