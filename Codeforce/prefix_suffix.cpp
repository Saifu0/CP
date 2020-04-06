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
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int t;
	cin >> t;
	while(t--){
		string s;
		cin >> s;
		int n = s.length();
		
		int c = 0;
		int l=0; 
		int r=n-1;
		while(true){
			if(s[l]==s[r]){
				l++;r--;
				c++;
			}else{
				break;
			}
			
		}
		
		int pre = 0;
		int i = l;
		int j=r;
		while(i<=j){
			if(s[i]==s[j]){ pre++;}
			j--;
		}
		int suf = 0;
		i = l;
		j=r;
		while(i<=j){
			if(s[i]==s[j]){suf++;}
			i++;
		}
		
		cout << c << " " << pre << " " << suf << endl; 
		
	
		
	}
	
	return 0;
}
