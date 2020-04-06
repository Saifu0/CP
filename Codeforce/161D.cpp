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
// #ifndef ONLINE_JUDGE
// 	freopen("input.txt", "r", stdin);
// 	freopen("output.txt", "w", stdout);
// #endif
}


//int a[mxn];

int main(){
	c_p_c();

	queue<ll> q;
	fo(i,9) q.push(i+1);
	int n; cin >> n;

	fo(i,n){
		ll temp = q.front();
		if(i+1==n){
			cout << temp << endl;
			break;
		}
		q.pop();
		if(temp%10!=0){
			q.push((temp*10)+(temp%10)-1);
		}
		q.push((temp*10)+(temp%10));
		if(temp%10!=9){
			q.push((temp*10)+(temp%10)+1);
		}
	}


	return 0;
}