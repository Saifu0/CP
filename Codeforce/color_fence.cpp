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



int main(){
	c_p_c();
	int v; cin >> v;
	int a[10];
	
	fo(i,9) cin >> a[i];
	//sort(a,a+9);

	int mn = *min_element(a,a+9);

	if(mn > v){
		cout << -1 << endl;
		return 0;
	}

	while(true){
		int len = v/mn;
		if(len==0) break;

		for(int j=8;j>-1;j--){
			if(v>=a[j]){
				int nlen = (v-a[j])/mn;
				if(len-1==nlen){
					cout << j +1;
					v -= a[j];
					break;
				}
			}
		}
	}


	return 0;
}