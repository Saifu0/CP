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

void solve(){
	int n; cin >> n;
	vi a(n);
	fo(i,n) cin >> a[i];
	a.pb(a[0]);

	bool one = true;
	fo(i,n){
		if(a[i] != a[i+1]){
			one=false;
			break;
		}
	}

	if(one){
		cout << 1 << endl;
		fo(i,n) cout << 1 << " ";
		cout << endl;
		return;
	}

	bool two = (n%2)==0;
	int equal = -1;
	if(n%2 != 0){
		fo(i,n){
			if(a[i] == a[i+1]){
				equal = i;
				break;
			}
		}
		if(equal >=0) two = true;
	}
	if(two){
		equal = max(equal+1,0);
		cout << 2 << endl;
		vi ans(n,0);
		fo(i,n){
			ans[(equal+i)%n] = 1 + i%2;
		}
		fo(i,n) cout << ans[i] << " " ;
		cout << endl;
		return;
	}
	cout << 3 << '\n';
 
    for (int i = 0; i < n; i++) {
        int value = 1 + i % 2;
 
        if (i == n - 1)
            value = 3;
 
        cout << value << " ";
    }
    cout << endl;
}

int main(){
	c_p_c();

	int t; cin >> t;
	while(t--){
		solve();
		
	}

	return 0;
}