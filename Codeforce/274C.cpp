#include<bits/stdc++.h>
using namespace std;
#define ll long long 

const int N = 5100;

struct Node {
	ll a,b;
};

bool compare(Node x, Node y){
	if(x.a == y.a) return x.b < y.b;
	return x.a < y.a;
}

int main(){
	int n;
	cin >> n;

	Node  d[N];
	for(int i=0;i<n;i++){
		cin >> d[i].a >> d[i].b;	
	}
	sort(d,d+n,compare);

	ll start = min(d[0].a,d[0].b);

	for(int i=1;i<n;i++){
		if(d[i].b >= start)
			start = d[i].b;
		else
			start = d[i].a;
	}

	cout << start << endl;
}
