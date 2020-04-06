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

const int mxn  = 2e6;
int n,m;
int l[mxn];
ll suff[mxn];

int main(){
    c_p_c();
    cin >> n >> m;
    ll sum = 0;
    Fo(i,1,m+1){
        cin >> l[i];
        sum += l[i];
        if(l[i]+i-1 > n){
            cout << -1 << endl;
            return 0;
        }
    }

    if(sum < n){
        cout << -1 << endl;
        return 0;
    }

    for(int i=m;i>=1;i--) suff[i] = suff[i+1] + l[i];

    Fo(i,1,m+1){
        cout << max((ll)i,n-suff[i]+1) << " ";
    }
    cout << endl;


    return 0;
}