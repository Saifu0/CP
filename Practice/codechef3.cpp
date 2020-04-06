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
	int t;
	cin >> t;
	while(t--){
		int r,c;
		cin >> r >> c;
		cout << 45 << endl;
		int x[] = {1,2,3,4,5,6,7,8,7,8,7,6,5,4,3,2,1,2,3,4,5,6,7,8,7,6,5,4,3,2,1,2,3,4,5,6,7,8,7,6,5,4,3,2,1};
		int y[] = {1,2,1,2,3,4,5,6,7,8,7,8,7,6,5,4,3,4,3,2,1,2,3,4,5,6,7,8,7,6,5,6,5,4,3,2,1,2,3,4,5,6,7,8,7};
		
		for(int i=0;i<45;i++){
		    cout << x[i] << " " << y[i] << endl;
		}

	}
	
	return 0;
}


