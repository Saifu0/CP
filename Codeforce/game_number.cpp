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
#define INT_SIZE sizeof(int)
#define INT_BITS INT_SIZE * 8 - 1 

void c_p_c()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
// #ifndef ONLINE_JUDGE
// 	freopen("input.txt", "r", stdin);
// 	freopen("output.txt", "w", stdout);
// #endif
}

ll countUnsetBits(ll n) 
{ 
    ll x = n; 
   
    n |= n >> 1; 
  
   
    n |= n >> 2; 
  
    n |= n >> 4; 
    n |= n >> 8; 
    n |= n >> 16; 
  
    return  __builtin_popcountll(x ^ n); 
} 




int main(){
	c_p_c();
	int t; cin >> t;
	while(t--){
		unsigned ll a,b; cin >> a >> b;

		unsigned ll cnt = 0;
		unsigned ll ans = 1;
		unsigned ll mxn = 0;

		int n=__builtin_popcountll(b);
		n += countUnsetBits(b);

		int m = __builtin_popcountll(a);//
		m += countUnsetBits(a);

		n = max(n,m);
		//const int t = n;
		bitset<64> z(a);
		bitset<64> x(b);

		//cout << n << endl;
		Fo(i,0,n){
			bitset<64> y = (x>>i | (x<<(n-i)));
			//cout << y << endl;
			bitset<64> w = z^y;
			unsigned ll r = 0;
			//cout << w << endl;
			fo(j,n){
			//	cout << w[j] << " ";
				r += (1<<j)*w[j];
			}
			//cout << r << endl;
				if(r>mxn){
				mxn = r;
							ans = cnt;
				}
				cnt++;

		}
		cout << ans << " " << mxn << endl;
		
	}

	return 0;
}