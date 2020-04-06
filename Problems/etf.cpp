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

void solve(int*arr){
	fo(i,1000002)
		arr[i] = i;

	for(int i=2;i<1000002;i++){
		if(arr[i] == i){
			arr[i] -= 1;
			for(int j=2*i;j<1000002;j+=i){
				arr[j] = (arr[j]*(i-1))/i;
			}
		}
	}
}


int main(){
	int t;
	cin >> t;
	int*arr = new int[1000002];
	solve(arr);
	while(t--){
		int n;
		cin >> n;
		cout << arr[n] << endl;
	}

	
	return 0;
}


