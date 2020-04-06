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

const int N = 12345678;
bool prime[N];


void sieve() 
{ 
    
    memset(prime, true, sizeof(prime)); 
  
    for (int p=2; p*p<=N; p++) 
    { 
        
        if (prime[p] == true) 
        {  
            for (int i=p*2; i<=N; i += p) 
                prime[i] = false; 
        } 
    } 
} 

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	sieve();
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		vi  v(n);
		fo(i,n) cin >> v[i];
		
		ll cnt=0;
		fo(i,n){
			Fo(j,i+1,n){
				if(prime[v[i]+v[j]]) cnt++;
			}
		}
		cout << cnt << endl;
	}
	
	return 0;
}
