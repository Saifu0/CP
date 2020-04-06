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
#define S second
#define F first

const int N = 2345;
int a[N];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n; cin >> n;
	Fo(i,1,n+1) cin >> a[i];
	
	int ans = 1;
	Fo(i,1,n+1){
		int num = 1;
		int x = i;
		while(a[x] != -1){ num++; x = a[x]; }
		if(num > ans) ans = num;
	}
	cout << ans << endl;
	
	
	
	return 0;
}
