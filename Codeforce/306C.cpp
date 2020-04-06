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
		int temp = s[i]-'0';
		if(temp%8==0) {cout << "YES" << endl << temp << endl; return 0;}
	}
	
	fo(i,n) Fo(j,i+1,n){
		int temp = (s[i]-'0')*10 + (s[j]-'0');
		if(temp%8==0) {cout << "YES" << endl << temp << endl; return 0;}
	}
	
	fo(i,n) Fo(j,i+1,n) Fo(k,j+1,n){
		int temp = (s[i]-'0') *100+ (s[j]-'0')*10 + s[k]-'0';
		if(temp%8==0) {cout << "YES" << endl << temp << endl; return 0;}
	}
	cout << "NO" << endl;
	return 0;
}
