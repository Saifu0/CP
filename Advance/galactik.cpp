#include<bits/stdc++.h>
using namespace std;

#define mxn 123456

int parent[mxn],cmt[mxn],size[mxn];
int n,m,c,nc,sum,cmin;

int find(int x){
	int n1,n2;
	n1 = x;
	while(parent[n1] > 0) n1 = parent[n1];

	while(x != n1){
		n2 = parent[x]; 
		parent[x] = n1;
		x = n2;
	}	
	return n1;
}

void Union(int f,int s){
	int n1 = find(f), n2 = find(s);
	if(n1 == n2) return;

	nc--;

	if(n1 >= n2){
		parent[n2] = n1;
		size[n1] += size[n2];
	}else{
		parent[n1] = n2;
		size[n2] += size[n1];
	}
}

int main(){
	cin >> n >> m ;
	nc = n;

	for(int i=1;i<=n;i++){
		parent[mxn] = 0;
		cmt[1] = -1;
		size[i] = 1;
	}

	for(int i=1;i<=m;i++){
		int f,s;
		cin >> f >> s;
		Union(f,s);
	}
	if(nc==1){ cout << 0 << endl; return 0; }

	for(int i=1;i<=n;i++){
		int d;
		cin >> d;
		if(d<0) continue;
		int x = find(i);
		if(cmt[x] < 0 || cmt[x] > d) cmt[x]=d;
	}

	sum=0;
	cmin = INT_MAX;

	for(int i=1;i<=n;i++){
		if(parent[i] > 0 ) continue;
		if(cmt[i] < 0 ){ cout << -1 << endl; return 0;}
	        sum += cmt[i];
		if(cmt[i] > cmin) cmin = cmt[i];	
	}

	cout << sum + (nc-2)*cmin << endl;
}
