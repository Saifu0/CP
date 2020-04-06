#include<bits/stdc++.h>
using namespace std;

#define sc(x) scanf("%d",&x)
#define pf(c) scanf("%d",x);
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

int main(){
	string s;
	cin >> s;
	int n = s.length();
	fo(i,n){
		if(s[i]=='-' && s[i+1]=='.' && (i+1)<n){ cout << 1; i++;}
		else if(s[i]=='-' && s[i+1]=='-' && (i+1)<n){ cout << 2; i++;}
		else cout << 0;
	}
	cout << endl;
	
	return 0;
}
