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

//if(s[i]=='L'){ start = start -1; }
			// if(s[i]=='R'){ start = start + 1;}
			// if(s[i]=='U'){ end = end+1; }
			// if(s[i]=='D'){ end = end - 1;}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		string s;
		cin >> s;
		
		int start=0,end=0;
		
		string a = "";
		int flag1 = 0, flag2 = -1;
		fo(i,n){
			
			
			 if(s[i]=='L' && flag1==0){
			 	start -= 1;
			 	flag1 = 1;
			 	flag2 = -1;
			 }
			 if(s[i]=='R' && flag1==0){
			 	start += 1;
			 	flag1 = 1;
			 	flag2 = -1;
			 }
			 if(s[i]=='U' && flag2==-1){
			 	end += 1;
			 	flag2 = -2;
			 	flag1 = 0;
			 }
			 if(s[i]=='D' && flag2==-1){
			 	end -= 1;
			 	flag2 = -2;
			 	flag1 = 0;
			 }
		}
		
		//cout << a << endl;
		
		cout << start << " " << end << endl;
	}
	
	return 0;
}
