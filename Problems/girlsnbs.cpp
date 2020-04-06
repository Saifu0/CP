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
	int girl,boy;
	cin >> girl >> boy;
	while(girl!= -1 && boy != -1){
		
		if(girl == boy){
			if(girl==0)
				cout << 0 << endl;
			else
				cout << 1 << endl;

		}else{
			int ma = max(girl,boy);
			int mi = min(girl,boy);
			if(ma%(mi+1) == 0)
				cout << ma/(mi+1) << endl;
			else
				cout << ma/(mi+1)+1 << endl;
			}
			cin >> girl >> boy;
	}
	
	return 0;
}


 