#include<bits/stdc++.h>
using namespace std;

struct node {
	int sum;
	node *l;
	node *r;
	node (){

	}
};

typedef node* pnode;

int get(pnode &p){
	return p ? p->sum : 0;
}

pnode initialize(int value){
	pnode p = (pnode)malloc(sizeof(node));
	p->sum = value;
	p->l = NULL;
	p->r = NULL;
	return p;
}

void add(pnode &p, int value){
	pnode current = p;
	for(int i=31;i>=0;i--){
		int b = (value>>i)&1;
		if(b==0){
			if(!current->l){
				current->l = initialize(0);
			}
			current = current->l;
		}else{
			if(!current->r){
				current->r = initialize(0);
			}
			current = current->r;
		}
		current->sum++;
	}
}

int get(pnode &p, int prefix, int value){
	int result = 0;
	pnode current = p;
	for(int i=31;i>=0;i--){
		if(!current) break;

		int pb = (prefix>>i)&1;
		int b = (value>>i)&1;

		if(pb == b){
			if(pb == 1){
				result += get(current->r);
			}
			current = current->l;
		}else{
			if(pb == 0){
				result += get(current->l);
			}
			current = current->r;
		}
	}
	return result;
}

int t,n,k;
int data[100005], prefix[10005];
pnode root;

int main(){
	cin >> t;
	while(t--){
		cin >> n >> k;
		for(int i=1;i<=n;i++){
			cin >> data[i];
		}
		root = initialize(0);
		add(root,0);
		long long result = 0;

		for(int i=1;i<=n;i++){
			prefix[i] = prefix[i-1] ^ data[i];
			result += get(root,prefix[i],k);
			add(root, prefix[i]);
		}
		cout << result << endl;
	}
	return 0;
}