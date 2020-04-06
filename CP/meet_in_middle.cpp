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
	int n;
	cin >> n;
	vi a(n);
	fo(i,n);
	int x; cin >> x;

	vi s1((n+1)/2),s2(n-(n+1)/2);


	return 0;
}


//Find subset of sum x
//Time complexity O(2^n/2)
//Test Case: 
/* n=4
   a[] =2 4 5 9
   x =15 */
//Output=[4,9]
