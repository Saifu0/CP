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

const int N = 1234;
string str[N];
int a[N];

int main(){
	c_p_c();

	int n;
	cin >> n;
	map<string,int> m,mm;

	fo(i,n){
		cin >> str[i] >> a[i];
		m[str[i]] += a[i];
	}

	int mx = INT_MIN;
	string ans;
	for(auto it=m.begin();it!=m.end();it++){
		if(it->S > mx){
			mx = it->S;
		}
	}

	fo(i,n){
		mm[str[i]] += a[i];
		if(mm[str[i]]>=mx && m[str[i]]==mx){
			cout << str[i] << endl;
			 break;
		}
	}

	cout << ans << endl;
	return 0;
}