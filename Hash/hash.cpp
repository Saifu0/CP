#include<bits/stdc++.h>
using namespace std;

#define MAX 100005

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

struct lib {
	ll nb,signup,bpd;
	map<ll, vi > mps(MAX);
	ll s_lib;
};

bool compare(lib a, lib b){
	return a.s_lib > b.s_lib;
}

ll find_n(lib *L, ll days, ll library){

	ll i=0, count=0;
	ll sum=0;
	while(days >= sum && library > i){
		sum += L[i].signup;
		count++;
		i++;
	}

	return count;

}


map<ll, vector<ll>> solve(lib*L, ll library, ll*wt, ll n, ll days){
	map<ll,vector<ll> > m;
	for(ll start = 0;start<n;start++){
		//days = (days-L[start].signup);
		
		// ll d = days*L[start].bpd;
		// //cout << L[start].nb << " ";
		// // d = d >= L[start].mps[start].size() ? L[start].mps[start].size() : d;
		// // cout << L[start].bpd<< " ";
		// if(days > L[start].nb || days<0)
		// 	days = L[start].nb;
		//cout << L[start].nb << " ";
		// cout << L[start].mps[start].size() << " ";
		//sort(L[start].mps[start].begin(), L[start].mps[start].end(), greater<ll>());
		for(ll i=0;i<50;i++){
			m[start].push_back(L[start].mps[start][i]);
		}
	}
	return m;
}

int main(){
	string s[] = {"a_example","b_read_on","c_incunabula","d_tough_choices","e_so_many_books", "f_libraries_of_the_world"};

	for(ll i=0;i<6;i++){
		string filename = s[i];
		string input_path = filename + ".in";
		string output_path = filename + ".out";

		

		auto hi = freopen(input_path.c_str(),"r", stdin);

		ll nob,library, days;
		cin >> nob >> library >> days;
		ll*wt = new ll[nob];

		fo(i,nob){
			cin >> wt[i];
		}
		lib L[library];
		fo(i,library){
			cin >> L[i].nb >> L[i].signup >> L[i].bpd ;
			fo(j,L[i].nb){
				ll data;
				cin >> data;
				L[i].mps[i].pb(data); 
			}
			L[i].s_lib = (days-L[i].signup )*L[i].bpd ;
		}

		sort(L,L+library, compare);
		auto out = fopen(output_path.c_str(), "w");
		ll n = find_n(L, days, library);
		map<ll, vector<ll> > m = solve(L,library,wt,n, days);

		fprintf(out, "%lld \n", n);
		for(ll i=0;i<n;i++){
			fprintf(out, "%lld ",i);
			fprintf(out, "%lld\n",  m[i].size() );
			for(ll j=0;j<m[i].size();j++){
				fprintf(out,"%lld ", m[i][j]);
			}
			fprintf(out, "\n");
		}

		
		fclose(out);
	
	}


	return 0;
}


