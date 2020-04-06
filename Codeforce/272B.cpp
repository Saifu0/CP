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

	string s1,s2;
	cin >> s1 >> s2;
	int need = 0;
	fo(i,s1.size()) need += (s1[i]=='+' ? 1 : -1);

	int m = s2.size();
	int n = s1.size();

	int a[m];
	int curr = 0;

	int move=0;
	fo(i,m){
		if(s2[i]=='?') move++;
		else curr += (s2[i]=='+' ? 1 : -1);
	}

	
	double ans = 0;
	int dist = need - curr;
	if((dist+move)%2!=0 || move<abs(dist)) ans = 0;
	else{
		int m = (move + abs(dist))/2;
		int c=1;
		fo(i,m) c*=(move-i);
		Fo(i,2,m+1) c/=i;
		ans = (double)c/(1<<move);
	}

	printf("%.12f\n",ans) ;


	return 0;
}