#include<bits/stdc++.h>
using namespace std;

void build(long long int*seg,int low,int high,int node)
{
    if(low>high)
    return;
    if(low == high)
    {
        seg[node]=0;
        return;
    }
    int mid = (low+high)/2;
    build(seg, low,mid,2*node+1);
    build(seg,mid+1,high,2*node+2);
    seg[node]=seg[2*node+1]+seg[2*node+2];
}

void update_lazy(long long int* tree, long long int* lazy, int low, int high, int startR, int endR, int currPos, int value){
	if(low > high) return;
	if(lazy[currPos] != 0){
		tree[currPos] += (high-low+1)*lazy[currPos];
		if(low != high){
			lazy[2*currPos] += lazy[currPos];
			lazy[2*currPos + 1] += lazy[currPos];
		}
		lazy[currPos] = 0;
	}
	if(startR > high || endR < low) return;
	if(startR <= low && high <= endR){
		tree[currPos] += (high-low+1)*value;
		if(low != high){
			lazy[2*currPos] += value;
			lazy[2*currPos + 1] += value;
		}
		return;
	}

	int mid = (low + high)/2;
	update_lazy(tree, lazy, low, mid, startR, endR, 2*currPos , value);
	update_lazy(tree, lazy, mid+1, high, startR, endR, 2*currPos+1 , value);

	tree[currPos] = tree[currPos*2] + tree[2*currPos + 1];

}

long long int query(long long int* tree,long long int*lazy, int start, int end, int low, int high, int index){

	if(lazy[index]!= 0){
		tree[index] += (end-start+1)*lazy[index];
		if(start != end){
			lazy[2*index] += lazy[index];
			lazy[2*index+1] += lazy[index];
		}
		lazy[index] = 0;
	}

	if(low <= start && high >= end){
		return tree[index];
	}

	if(low > end || start > high) return 0;

	int mid = (start + end)/2;
	return query(tree, lazy,start, mid, low, high, 2*index) + 
		query(tree,lazy, mid+1, end, low, high, 2*index+1);
}

int main(){
	int t;
	cin >> t;
	while(t--){
		int n,c;
		cin >> n >> c;
		long long int* tree = new long long int[4*n]();
		long long int* lazy = new long long int[4*n]();
		build(tree, 0, n-1, 1);
		for(int i=0;i<c;i++){
			int type;
			cin >> type;
			
			if(type == 0){
				int start, end, value;
				cin >> start >> end >> value;
				update_lazy(tree, lazy, 0, n-1, start-1, end-1, 1, value);
			}
			if(type == 1){
				int start, end;
				cin >> start >> end;
				cout << query(tree,lazy, 0, n-1, start-1, end-1, 1) << "\n";
			}
		
		}
	}
}