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
#define m map<int,int>

int main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		string s;
		cin >> s;
		map<string,int> mp;
		

		int sz = s.length();

		fo(i,sz-2){
			if(s[i] == 'T' && s[i+1] == 'T' && s[i+2] == 'T')
				mp["TTT"]++;
			else if(s[i] == 'T' && s[i+1] == 'T' && s[i+2] == 'H')
				mp["TTH"]++;
			else if(s[i] == 'T' && s[i+1] == 'H' && s[i+2] == 'T')
				mp["THT"]++;
			else if(s[i] == 'T' && s[i+1] == 'H' && s[i+2] == 'H')
				mp["THH"]++;
			else if(s[i] == 'H' && s[i+1] == 'T' && s[i+2] == 'T')
				mp["HTT"]++;
			else if(s[i] == 'H' && s[i+1] == 'T' && s[i+2] == 'H')
				mp["HTH"]++;
			else if(s[i] == 'H' && s[i+1] == 'H' && s[i+2] == 'T')
				mp["HHT"]++;
			else if(s[i] == 'H' && s[i+1] == 'H' && s[i+2] == 'H')
				mp["HHH"]++;
		}
		cout << n << " " << mp["TTT"] << " " << mp["TTH"] << " " << mp["THT"] << " " << mp["THH"] << " " << mp["HTT"] << " " << mp["HTH"] << " " << mp["HHT"] << " " << mp["HHH"] << endl;

	}
	
	return 0;
}


