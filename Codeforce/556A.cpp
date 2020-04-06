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
	int n,m,r;
	cin>>n>>m>>r;
	int min=INT_MAX,max=INT_MIN;
	fo(i,n){
		int d;
		cin >>d;
		if(min > d) min = d;
	} 
	fo(i,m){
		int d;
		cin >> d;
		if(max<d) max = d;
	}

	int temp = r;
	int rem = r%min;
	int q = temp/min;
	int ans = rem + max*q;
	ans = ans > temp ? ans : temp;

	cout << ans << endl;
	
	return 0;
}


