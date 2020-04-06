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

int sieve[10000];
vector<int> adj[10000];

void make_graph(){
	for(int i=1001;i<10000;i++){
		if(sieve[i] == 0)
			continue;


		for(int j=0;j<4;j++){
			int t = pow(10,j);
			int prev,digit,last;
			prev = i/t;
			digit = prev%10;
			prev /= 10;
			last = i%t;
			for(int k=0;k<=9;k++){
				if(k==digit) continue;

				int num = prev*t*10 + t*k + last;
				if(sieve[num])
					adj[i].pb(num);
			}
		}
	}
}

int solve(int f, int s){
	fo(i,10000)
		sieve[i] = 1;

	for(int i=2;i<sqrt(10000);i++){
		if(sieve[i] == 1)
		for(int j=i+i;j<10000;j+=i){
			sieve[j] = 0;
		}
	}
	make_graph();
	
	if(f==s) return 0;

	bool check[10000];
	for(int i=0;i<10000;i++){
		check[i] = false;
	}

	queue<ii> q;
	check[f] = true;
	q.push(make_pair(f,0));

	while(!q.empty()){
		ii temp = q.front();
		q.pop();
		vector<int>::iterator it;
		for(it=adj[temp.first].begin();it!=adj[temp.first].end();it++){
			if(!check[*it]){
				check[*it] = true;
				if(*it == s) return temp.second+1;

				q.push(make_pair(*it,temp.second+1));
			}
		}

	}


	return -1;
}

int main(){
	int t;
	cin >> t;
	while(t--) {
	    int f,s;
	    cin >> f >> s;
	    cout << solve(f,s) << endl;
	}
	
	return 0;
}


