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

int block;
int freq[1000005];

struct Query {
	int l,r,index,ans;
};

bool compare(Query a, Query b){
	if(a.l/block != b.l/block)
		return a.l/block < b.l/block;

	return a.r < b.r;
}

bool compare2(Query a, Query b){
	return a.index < b.index;
}

void solve(int*arr, int n, Query *q, int m){
	block = (int)sqrt(n);

	sort(q,q+m,compare);

	int count = 0;
	int start = 0,end= 0;

	vector<Query> v;
	for(int i=0;i<m;i++){
		int L = q[i].l, R = q[i].r;

		while(start < L){
			start++;
			freq[arr[start]]++;
			if(freq[arr[start]] == 1)
				count++;
		}

		while(start > L){
			start--;
			freq[arr[start]]--;
			if(freq[arr[start]] == 0)
				count--;
		}

		while(end < R){
			end++;
			freq[arr[end]]++;
			if(freq[arr[end]] == 1)
				count++;
		}

		while(end > R){
			end--;
			freq[arr[end]]--;
			if(freq[arr[end]]==0)
				count--;
		}

		q[i].ans = count;
		v.pb(q[i]);
	}

	sort(v.begin(),v.end(),compare2);


	for(int i=0;i<m;i++)
		cout << v[i].ans << endl;
}

int main(){
	int n;
	cin >> n;
	int*arr = new int[n];
	fo(i,n)
		cin >> arr[i];

	int m;
	cin >> m;
	Query *q = new Query[m];
	fo(i,m){
		int f,s;
		cin >> f >> s;
		q[i].l = f-1;
		q[i].r = s-1;
		q[i].index = i;
	}

	solve(arr, n, q, m);

	
	return 0;
}


