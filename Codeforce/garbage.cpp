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

const int mxn = 2e6;
ll n,m,c,k;
ll p[mxn],d[mxn];


int main(){
    c_p_c();

    cin >> n >> m >> c >> k;
    k += 1;

    fo(i,n) cin >> p[i] >> d[i];

    ll ans = 0;
    int cnt = 0;

    bool flag=false;
    fo(i,n){
        if(c/k > d[i]) continue;
        else if(c/k == d[i] || flag==true){
            c += p[i];
            cnt++;
            flag=false;
        }else{
            i--;
            flag=true;
            continue;
        }
    }

    cout << cnt << endl;


    return 0;
}