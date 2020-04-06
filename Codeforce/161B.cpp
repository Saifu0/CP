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
#define F first
#define S second
#define sz(v) (int)v.size()
#define mod 1000000007

void c_p_c()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}

bool cmp(int a, int b){
	return a > b;
}

int main(){
	c_p_c();
	int n,m; cin >> n >> m;
	ll sum = 0;
	int a[n];
	fo(i,n){
		cin >> a[i];
		sum += a[i];
	}
	//sum += 1;

	//bool flag = false;
	// int cnt = 0;
	// sort(a,a+n,cmp);
	// fo(i,n){
	// 	if(a[i] < sum/(4*m)) break;
	// 	cnt++;
	// }

	// if(cnt>=m) cout << "Yes" << endl;
	// else cout << "No" << endl;

	if(a[m-1] >= sum/(4*m)) cout << "Yes" << endl;
	else cout << "No" << endl;

	return 0;
}