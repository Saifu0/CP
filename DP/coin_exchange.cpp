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

int solve(int*arr, int change, int n){
	if(n==0) return 0;
	if(change == 0) return 1;
	if(change<0) return 0;

	int first = solve(arr,change-arr[0], n);
	int second = solve(arr+1,change, n-1);

	return first+second;
 }

int main(){
	int n;
	cin >> n;
	int* arr = new int[n];

	fo(i,n) cin >> arr[i];

	int change;
	cin >> change;

	cout << solve(arr,change,n) << endl;
	
	return 0;
}


