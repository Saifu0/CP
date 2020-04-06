#include<bits/stdc++.h>
using namespace std;

#define deb(x) cout << #x << " " << x << endl;
#define fo(i,n) for(int i=0;i<n;i++)
#define Fo(i,k,n) for(int i=k,i<n;i++)
#define vi vector<int>
#define ii pair<int,int>
#define vii vector<ii>
#define ll long long
#define pb push_back
#define endl "\n"
#define mp map<int,int>

struct Job
{
	int s,f,w;
};

bool compare(Job a, Job b){
	return a.f < b.f;
}


int solve(Job* J, int n){
	int dp[n+1];
	memset(dp,0,sizeof(n+1));

	sort(J,J+n,compare);


	fo(i,n){
		dp[i] += J[i].w;
		for(int j=i-1;j>=0;j--){
			if(J[j].f <= J[i].s){
				dp[i] += J[j].w;
			}
		}
	}

	return dp[n-1];
}

int main(){
	int n;
	cin >> n;

	Job J[n];

	fo(i,n){
		cin >> J[i].s >> J[i].f >> J[i].w;
	}	


	cout << solve(J, n) << endl;
	
	return 0;
}


