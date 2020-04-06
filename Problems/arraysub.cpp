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
	fo(i,n){
		cin >> arr[i];
	}
	int k;
	cin >> k;

	for(int i=0;i<n-k+1;i++){
		int *it;
		it = max_element(arr+i,arr+k+i);
		cout << *it << " ";
	}

	cout << endl;
	
	return 0;
}





