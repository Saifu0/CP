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
	string s;
	cin >> s;
	int track=1;
	while(s[0] != '-'){
		int n = s.length();
		int o=0;
		int c=0;
		fo(i,n){
			if(s[i]=='{'){
				o++;
			}else{
				o--;
				if(o<0){
					o=1;
					c++;
				}
			}
		}
		int count = c+o/2;
		cout << track << ". " << count << endl;
		track++;
		cin >> s;
	}
	
	return 0;
}


