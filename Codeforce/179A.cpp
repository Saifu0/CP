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

const int N = 1e5+7;
int n,m,k;
ll x[N],y[N],add[N],l[N],r[N],t[N],d[N],a[N];


int main(){
	c_p_c();
	cin >> n >> m >> k;
	Fo(i,1,n+1) cin >> a[i];
	Fo(i,1,m+1) cin >> l[i] >> r[i] >> d[i];
	Fo(i,1,k+1){
		cin >> x[i] >> y[i];
		t[x[i]]++;
		t[y[i]+1]--;
	}

	Fo(i,1,m+1){
		t[i] += t[i-1];
		add[l[i]] += t[i]*d[i];
		add[r[i]+1] -= t[i]*d[i];
	}

	Fo(i,1,n+1){
		add[i] += add[i-1];
		cout << add[i] + a[i] << " ";
	}
	cout << endl;

	return 0;
}