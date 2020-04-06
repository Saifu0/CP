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
	int n,k;
	cin >> n >> k;
	vector<ii > a(n);

	for(int i=0;i<n;i++){
		cin >> a[i].first;
		a[i].second = i;
	}

	sort(a.rbegin(),a.rend());
	queue<int> q;
	for(int i=0;i<n;i++){
		q.push(a[i].second);
	}

	set<int> idx;
	for(int i=0;i<n;i++)
		idx.insert(i);


	string ans(n,'0');
	int who = 0;

	while(!idx.empty()){
		while(!idx.count(q.front()))
			q.pop();

		int pos = q.front();
		q.pop();

		vector<int> add;

		auto it = idx.find(pos);

		for(int i=0;i<=k;i++){
			add.pb(*it);
			if(it==idx.begin()) break;
			--it;
		}
		it = next(idx.find(pos));
		for(int i=0;i<k;i++){
			if(it == idx.end()) break;
			add.pb(*it);
			++it;
		}

		for(auto i : add){
			idx.erase(i);
			ans[i] = '1' + who;
		}
		who ^= 1;
	}

	cout << ans << endl;
	
	return 0;
}


