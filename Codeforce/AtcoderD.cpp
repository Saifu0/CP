#include<bits/stdc++.h>
using namespace std;

#define sc(x) scanf("%d",&x)
#define pf(c) scanf("%d",x);
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



const int N = 100005;
//int a[N];
mp m;



int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n; cin>>n;
       int arr[n];
       map<int,int> m;
       for (int i = 0; i < n; i++)
	   {
			cin>>arr[i];   
			m[arr[i]]++;
	   }
	   int ans = 0;
	   for(auto x : m)
	   {
			ans += (x.second-1)*(x.second)/2;
	   }   
	   for (int i = 0; i < n; i++)
	   {
		   int cnt = m[arr[i]];
		   cout << ans - cnt + 1 <<endl;
	   }
	
	
	return 0;
}
