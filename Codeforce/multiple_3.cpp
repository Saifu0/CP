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

int main(){
	c_p_c();
	int t, d0, d1, i, d[4], s1, c;
    ll k, s, j;
    cin>>t;
    for(i=0;i<t;i++)
    {
        ll k;
		cin>>k;
		ll c,d;
		cin>>c>>d;
		if(k==2)
		{
			if((c+d)%3==0)
				cout<<"YES"<<endl;
			else
				cout<<"NO"<<endl;
		}
		else
		{
			ll ans = c+d+(c+d)%10;
			ll u = (c+d)%10;
			k-=3;
			
			ll r = (k/4)%3;
			ll q = k%4;
			ans += (r*((2*u%10+4*u%10+6*u%10+8*u%10)))%3;
			if(q==1)
			{
				ans += (2*u)%10%3;
			}
			else if(q==2)
			{
				ans += (2*u%10+4*u%10)%3;
			}
			else if(q==3)
			{
				ans += (2*u%10+4*u%10+8*u%10)%3;
			}

			if(ans%3==0)
				cout<<"YES"<<endl;
			else
				cout<<"NO"<<endl;
		}
    }

	return 0;
}

