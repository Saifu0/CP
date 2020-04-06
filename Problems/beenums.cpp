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
	ll n;
	cin >> n;

	while(n!=-1){
		int i=1,j=1;
		int flag=0;
		while(true){
			if(n==i){
				flag=1;
				break;
			}
			if(i>n){
				break;
			}
			i = i + j*6;
			j +=1;
		}
		if(flag==1) cout << "Y" << endl;
		else cout << "N" << endl;

		cin >> n;
	}
	
	return 0;
}


