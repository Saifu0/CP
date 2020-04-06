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
	int n;
	cin >> n;
	char ch[n][n];

	fo(i,n) fo(j,n) cin >> ch[i][j];

	fo(i,n)
		fo(j,n){
			if(ch[i][j] == '.' && ch[i-1][j]=='.' && ch[i+1][j]=='.' && ch[i][j+1]=='.' && ch[i][j-1]=='.' && j>0 && j<n-1 && i>0 && i<n-1){
				ch[i][j] = '#';
				ch[i+1][j] = '#';
				ch[i-1][j] = '#';
				ch[i][j+1] = '#';
				ch[i][j-1] = '#';
			}
		}

	int flag=0;
	fo(i,n)
		fo(j,n)
			if(ch[i][j] == '.'){
				flag=1;
				break;
			}

	if(flag==1) cout << "NO" << endl;
	else cout << "YES" << endl;
	
	return 0;
}


