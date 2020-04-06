#include<bits/stdc++.h>
using namespace std;

#define deb(x) cout << #x << " " << x << endl;
#define fo(i,n) for(int i=0;i<n;i++)
#define Fo(i,k,n) for(int i=k,i<n;i++)
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
	int* arr = new int[n];

	fo(i,n) cin >> arr[i];

	sort(arr,arr+n);

	int min = INT_MAX;

	fo(i,n-1){
		if(abs(arr[i]- arr[i+1])< min) min = abs(arr[i]-arr[i+1]);
	}

	cout << min << endl;
	
	return 0;
}



