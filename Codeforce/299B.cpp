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

const int N = 12345678;
int a[N],n;

int main(){
	c_p_c();

	cin >> n;

	if(n==4) { cout << 1 << endl; return 0; }
	if(n==7) { cout << 2 << endl; return 0; }
	
	

	a[0] = 4;
	a[1] = 7;

	int cnt=2;

	int j=0;
	int flip=0;


	for(int i=2;i<N;i++){
		
		if(flip==0) a[i] = a[i-2-j]*10 + 4,flip=1,j++;
		else a[i] = a[i-2-j]*10 + 7, flip=0;

		//cout << a[i] << endl;
		
		if(a[i]==n){ cnt = i+1; break;}
	}

	cout << cnt << endl;

	return 0;
}