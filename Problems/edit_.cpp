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

void solve(char* s,int n){
	if(s[0]=='\0') return;
	if(s[0] == 'x'){
		fo(i,n-1){
			s[i] = s[i+1];
		}
		s[n-2] = '\0';
		solve(s,n-1);
	}
	solve(s+1,n);
}

int main(){
	
	char s[100];
	cin >> s;
	
	solve(s, strlen(s));
	
	cout << s << endl;
	
	
	return 0;
}



