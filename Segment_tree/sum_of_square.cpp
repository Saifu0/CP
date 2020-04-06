#include<bits/stdc++.h>
using namespace std;

struct Tree {
	int ss;
	int s;
};


void buildTreeUtils(Tree* tree, int* arr, int start, int end, int index){
	if(start == end){
		tree[index].ss = arr[start]*arr[start];
		tree[index].s = arr[start];
		return;
	}

	int mid = (start + end)/2;
	buildTreeUtils(tree, arr, start, mid , 2*index);
	buildTreeUtils(tree, arr, mid+1, end, 2*index+1);

	tree[index].ss += (tree[2*index].ss + tree[2*index+1].ss);  
}

Tree* buildTree(int* arr, int n){
	Tree* tree = new Tree[4*n];
	buildTreeUtils(tree, arr, 0, n-1, 1);
	return tree;
}

int query(Tree* tree, int start, int end, int l , int r, int index){
	if(start > r || end < l){
		return -1;
	}
	if(start >= l && end <= r){
		return tree[index].ss;
	}

	int mid = (start + end)/2;

	int left = query(tree, start, mid, l, r, 2*index);
	int right = query(tree, mid+1, end, l, r, 2*index+1);

	return (left + right);
}

void update1(Tree* tree, int* lazy, int start, int end, int l, int r, int index, int x){
	if(start > end) return;

	if(lazy[index] != 0){
		tree[index].ss += (2*lazy[index]*tree[index].s + lazy[index]*lazy[index]*(r-l+1));
		tree[index].s += lazy[index]*(r-l+1);
		if(start != end){
			lazy[2*index] += lazy[index];
			lazy[2*index+1] += lazy[index];
		}
		lazy[index] = 0;
	}

	if(l > end || r < start ) return;

	if(l <= start && end <= r){
		tree[index].ss += (2*x*tree[index].s + x*x*(r-l+1));
		tree[index].s += x*(r-l+1);

		if(start != end){
			lazy[2*index] += x;
			lazy[2*index+1] += x;
		}
		return;
	}

	int mid = (start + end)/2;
	update1(tree, lazy, start, mid, l, r, 2*index, x);
	update1(tree, lazy, mid+1, end, l, r, 2*index+1, x);

	tree[index].ss = tree[2*index].ss + tree[2*index+1].ss;
	tree[index].s = tree[2*index].s + tree[2*index+1].s;

}

int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int n,q;
		scanf("%d%d",&n,&q);
		int arr[n];
		for(int i=0;i<n;i++){
			cin >> arr[i];
		}


		int type, start, end, x;
		Tree* tree = buildTree(arr, n);
		int* lazy = new int[4*n]();
		for(int i=1;i<4*n;i++){
			cout << tree[i].ss << " " << tree[i].s << endl;
		}
		while(q--){
			cin >> type;
			if(type == 2){
				cin >> start >> end;
				printf("%d\n", query(tree, 0, n-1, start-1, end-1, 1));

			}
			else if(type == 1){
				cin >> start >> end >> x;
				 update1(tree, lazy, 0, n-1, start-1, end-1, 1, x);
			}
		}
		//else{
		// 	cin >> start >> end >> x;
		// 	printf("%d\n", update0(tree, lazy, 0, n-1, start-1, end-1, 1, x));

		// }
	}
}