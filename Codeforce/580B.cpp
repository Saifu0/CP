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
	int n;
	cin >> n;
	ll sum=0,z=0,ne=0;
	fo(i,n){
		int x;
		cin >> x;
		if(x==0) z++,sum++;
		else if(x < 0) {
			sum += -1-x;
			ne++;
		}else{
			sum += x-1;
		}
	}
	
	if(ne&1 && z==0) sum += 2;
	cout << sum << endl;
	
	
	return 0;
}
