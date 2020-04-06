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

int solve(int n){
	if(n==0 || n==1) return 1;
	if(n==2) return 2;


	return solve(n-1) + solve(n-2) + solve(n-3);
}

int main(){
	int n;
	cin >> n;

	cout << solve(n) << endl;
	
	return 0;
}


