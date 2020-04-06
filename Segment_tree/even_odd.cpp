#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int odd,even;
};

void buildTree(Node* tree, int* arr, int start, int end, int index){
	if(start == end){
		tree[index].even = (arr[start]%2) == 0 ? 1 : 0;
		tree[index].odd  = (arr[start]%2) == 0 ? 0 : 1;
		return;
	}

	int mid = (start + end)/2;
	buildTree(tree, arr, start, mid, 2*index);
	buildTree(tree, arr, mid+1, end, 2*index+1);

	tree[index].even = tree[2*index].even + tree[2*index+1].even;

	tree[index].odd = tree[2*index].odd + tree[2*index+1].odd;
}

void update(Node* tree, int* arr, int start, int end, int treeInd, int index, int value ){
	if(start == end){
		arr[index] = value;
		tree[treeInd].even = (value%2) == 0 ? 1 : 0;
		tree[treeInd].odd  = (value%2) == 0 ? 0 : 1;

		return;
	}
	int mid = (start + end)/2;
	if(index <= mid)
		update(tree, arr, start, mid, 2*treeInd , index, value);
	else
		update(tree, arr, mid+1, end, 2*treeInd+1, index, value);

	tree[treeInd].even = tree[2*treeInd].even + tree[2*treeInd+1].even;
	tree[treeInd].odd = tree[2*treeInd].odd + tree[2*treeInd+1].odd;

}

Node query(Node* tree, int start, int end, int treeInd ,int l, int r){
	Node result;
	result.even = result.odd = 0;
	if(start > r || end < l) return result;
	if(start >= l && end <= r) return tree[treeInd];

	int mid = (start + end)/2;
	Node ans1 = query(tree, start , mid, 2*treeInd , l, r);
	Node ans2 = query(tree, mid+1, end, 2*treeInd+1, l, r);

	result.even = ans1.even + ans2.even;
	result.odd = ans1.odd + ans2.odd;

	return result;
}


int main(){
	int n;
	cin >> n;
	int arr[n];
	for(int i=0;i<n;i++){
		cin >> arr[i];
	}
	Node* tree = new Node[4*n];
	buildTree(tree, arr, 0, n-1, 1);

	// for(int i=1;i<2*n;i++){
	// 	cout << tree[i].even << " " << tree[i].odd << endl;
	// }
	int q;
	cin >> q;
	while(q--){
		int type,x,y;
		cin >> type ;
		if(type == 0){
			cin >> x >> y;
			update(tree,arr,  0, n-1, 1, x-1, y);
		}else{
			cin >> x >> y;
			Node res = query(tree, 0, n-1, 1, x-1, y-1);
			if(type == 1) cout << res.even << endl;
			else if(type == 2) cout << res.odd << endl;
		}
	}
}
 