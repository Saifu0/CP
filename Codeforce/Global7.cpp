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
#define S second
#define F first

const int M = (int)(2e6 + 239);
 
int pref[M], c;

string solve_palind(string s){
	string a = s;
	reverse(s.begin(),s.end());
	a = a + '#' + s;
	
	c = 0;
	//pref[0]  = 0 ;
	for(int i=1;i<(int)a.size();i++){
		while(c!=0 && a[c] != a[i]) c = pref[c-1];
		if(a[c]==a[i]) c++;
		pref[i] = c;
	}
	return a.substr(0,c);
}

void solve(){
	string s;
	cin >> s;
	
	int l=0;
	int n = s.length();
	while(l<(n-l-1)){
		if(s[l] != s[n-l-1]) break;
		l++;
	}
	
	if(l>0) cout << s.substr(0,l);
	if(n>2*l){
		string a = s.substr(l,n-2*l);
		//cout << a << endl;
		string x = solve_palind(a);
		reverse(a.begin(),a.end());
		string y = solve_palind(a);
		
		if(x.size() < y.size()) swap(x,y);
		cout << x;
	}
	//cout << endl;
	if(l>0)
	cout << s.substr(n-l,l);
	cout << endl;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--)
		solve();
	
	return 0;
}
