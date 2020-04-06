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
	int n,m;
	cin >> n >> m;

	string s(n,'1');

	int temp = n;
	int i=n-1;
	while(temp!=m){
		while(s[i] != 57 || temp!=m){
			s[i] +=1;
			temp=0;
			for(int j=0;j<n;j++){
				temp += s[j]-'0';
			}
		}
		i--;
	}

	cout << s << endl;
	
	return 0;
}


