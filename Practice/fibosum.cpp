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
#define mod 1000000007


void multiply(ll a[2][2], ll b[2][2]){
	ll M[2][2];

	fo(i,2){
		fo(j,2){
			M[i][j] = 0;
			fo(k,2){
				M[i][j] = (M[i][j]%mod + a[i][k]*b[k][j]%mod)%mod;
			}
		}
	}

	fo(i,2)
		fo(j,2)
			a[i][j] = M[i][j];

}

ll power(ll F[2][2], ll n){
	ll M[2][2] = {{1,1}, {1,0}}; 

	if(n==1)
		return F[0][0] + F[0][1];

	power(F,n/2);

	multiply(F,F);

	if(n%2 != 0){
		multiply(F,M);
	}

	return F[0][0] + F[0][1];
}

ll solve(ll n){
	ll F[2][2] = {{1,1}, {1,0}};

	if(n==0) return 0;

	if(n==1 || n==2) return 1;

	return power(F,n-2);
}

int main(){
	int t;
	cin >> t;
	
	while(t--){
		ll start,end;
		cin >> start >> end;

		
		cout << solve(end+2) - solve(start+1) << endl;
	}
	
	return 0;
}


