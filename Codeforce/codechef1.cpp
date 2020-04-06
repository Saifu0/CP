
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
	int t;
	cin >> t;
	while(t--){
		string s;
		cin >> s;
		int a=s[0],b=s[1],c=s[2];
		bool x=false,y=false,z=false;
		
		if(a=='P') x=true;
		if(a=='C') y = true;
		if(a=='M') z=true;
		if(b=='P') x=true;
		if(b=='C') y = true;
		if(b=='M') z=true;
		if(c=='P') x=true;
		if(c=='C') y = true;
		if(c=='M') z=true;
			
			if(x && y && z) cout << "YES" << endl;
			else cout << "NO" << endl;
		
	}
	
	
	return 0;
}
