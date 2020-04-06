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


	int cnt = 0;
	
	while(n!=0){
		if(n>=100){
			n -= 100;
			cnt++;
		}
		else if(n>=20){
			n -= 20;
			cnt++;
		}
		else if(n>=10){
			n -= 10;
			cnt++;
		}
		else if(n>=5){
			n -=5;
			cnt++;
		}
		else if(n>=1){
			n -= 1;
			cnt++;
		}
	}

	cout << cnt << endl;
	
	return 0;
}


