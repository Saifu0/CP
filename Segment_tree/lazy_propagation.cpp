#include<bits/stdc++.h>
using namespace std;

void buildTree(int* arr , int* tree, int start, int end, int treeNode){
	if(start == end){
		tree[treeNode] = arr[start];
		return;
	}

	int mid = (start + end)/2;

	buildTree(arr, tree, start, mid , 2*treeNode);
	buildTree(arr, tree, mid + 1,end, 2*treeNode+1);

	tree[treeNode] = min(tree[2*treeNode], tree[2*treeNode + 1]);

}

void updateLazy(int* tree, int* lazy, int low, int high, int startR,int endR, int currPos, int inc){
	if(low > high) return;

	if(lazy[currPos] != 0){
		tree[currPos] += lazy[currPos];

		if(low != high){
			lazy[2*currPos] += lazy[currPos];
			lazy[2*currPos + 1] += lazy[currPos];
		}
		lazy[currPos] = 0;
	}

	if(startR > high || endR < low) return;

	if(startR <= low && high <= endR){
		tree[currPos] += inc;
		if(low != high){
			lazy[2*currPos] += inc;
			lazy[2*currPos + 1] += inc;
		}
		return;
	}



	int mid = (low + high) / 2;

	updateLazy(tree, lazy, low , mid,startR, endR, 2*currPos , inc );
	updateLazy(tree, lazy, mid+1 , high,startR, endR, 2*currPos+1 , inc );

	tree[currPos] = min(tree[2*currPos] , tree[2*currPos+1]);
}

int main(){
	int arr[] = {1,3,-2,4};
	int* tree = new int[12];
	buildTree(arr, tree, 0, 3, 1);

	int* lazy = new int[12]();

	updateLazy(tree,lazy,0,3,0,3,1,3);
	updateLazy(tree, lazy, 0, 3, 0, 1, 1, 2);

	cout << "Segment tree" << "\n";
	for(int i=1;i<12;i++){
		cout << tree[i] << "\n";
	}

	cout << "Lazy tree" << "\n";
	for(int i=1;i<12;i++){
		cout << lazy[i] << "\n";
	}


	return 0;
}