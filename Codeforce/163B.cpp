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

int main(){
	int n,t;
	cin >> n >> t;
	string s;
	cin >> s;
	while(t--){
		for(int i=0;i<n-1;i++){
			if(s[i]=='B' && s[i+1]=='G'){
				swap(s[i],s[i+1]);
				i += 1;
			}
		}
	}

	cout << s << endl;
	
	return 0;
}


