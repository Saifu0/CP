#include<bits/stdc++.h>
using namespace std;

#define deb(x) cout << #x << " " << x << endl;
#define fo(i,n) for(int i=0;i<n;i++)
#define Fo(i,k,n) for(int i=k,i<n;i++)
#define vi vector<int>
#define ii pair<int,int>
#define vii vector<ii>
#define ll long long
#define pb push_back
#define endl "\n"
#define mp map<int,int>

int subs(string s, string* out){
	if(s.empty()){
		out[0] = "";
		return 1;
	}
	
	string small = s.substr(1);
	int smallsize = subs(small,out);
	
	fo(i,smallsize) out[i+smallsize] = s[0] + out[i];
	return 2*smallsize;
}

int main(){
	string s;
	cin >> s;
	string* out = new string[1000];
	
	int n = subs(s,out);
	fo(i,n) cout << out[i] << endl;
	
	return 0;
}



