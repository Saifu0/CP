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

int solve(int a, int b){
	if(b==0) return a;
	return solve(b,a%b);
}

int main(){
	int t;
	cin >> t;
	while(t--) {
	    int a;
		string s;
		cin >> a >> s;

		int b = 0;

		if(a!=0)
		for(int i=0;i<s.length();i++){
			b = (b*10 + s[i]-'0')%a;
		}
		if(a==0){
			cout << s << endl;
			continue;
		}

		if(b==0) {
			cout << a << endl;
			continue;
		}
		

		cout << solve(a,b) << endl;
	}
	
	
	return 0;
}


