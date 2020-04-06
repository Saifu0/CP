// #include<bits/stdc++.h>
// using namespace std;
// 
// 
// #define deb(x) cout << #x << " " << x << endl;
// #define fo(i,n) for(int i=0;i<n;i++)
// #define Fo(i,k,n) for(int i=k;i<n;i++)
// #define vi vector<int>
// #define ii pair<int,int>
// #define vii vector<ii>
// #define ll long long
// #define pb push_back
// #define endl "\n"
// #define mp map<int,int>
// #define S second
// #define F first
// 
// const int N = 123456;
// 
// struct Tree {
	// ll sum,pref,suf,max_sum;
// };
// 
// Tree tree[4*N];
// 
// void build(int a[], int start, int end, int ind){
	// if(start==end){
		// tree[ind].sum = a[start];
		// tree[ind].pref = a[start];
		// tree[ind].suf = a[start];
		// tree[ind].max_sum = a[start];
	// }else{
		// int mid = (start + end)/2;
// 	
		// build(a,start,mid,2*ind);
		// build(a,mid+1,end,2*mid+1);
// 		
		// tree[ind].sum = tree[2*ind].sum + tree[2*ind+1].sum;
		// tree[ind].pref = max(tree[2*ind].pref, tree[2*ind].sum + tree[2*ind+1].pref);
		// tree[ind].suf = max(tree[2*ind].suf,tree[2*ind].sum + tree[2*ind+1].suf);
		// tree[ind].max_sum = max({tree[2*ind].max_sum,tree[2*ind+1].max_sum, tree[2*ind].pref + tree[2*ind+1].suf, tree[ind].pref,tree[ind].suf });
	// }
// }
// 
// void update(int a[],int start, int end, int ind, int i, int val){
	// if(start==end){
		// tree[ind].sum = a[start];
		// tree[ind].pref = a[start];
		// tree[ind].suf = a[start];
		// tree[ind].max_sum = a[start];
	// }else{
		// int mid = (start+end)/2;
		// if(i<=mid) update(a,start,mid,2*ind, i, val);
		// else update(a,mid+1,end,2*ind+1,i,val);
// 		
		// tree[ind].sum = tree[2*ind].sum + tree[2*ind+1].sum;
		// tree[ind].pref = max(tree[2*ind].pref, tree[2*ind].sum + tree[2*ind+1].pref);
		// tree[ind].suf = max(tree[2*ind].suf,tree[2*ind].sum + tree[2*ind+1].suf);
		// tree[ind].max_sum = max({tree[2*ind].max_sum,tree[2*ind+1].max_sum, tree[2*ind].pref + tree[2*ind+1].suf, tree[ind].pref,tree[ind].suf });
// 	
// 
	// }
// 	
// }
// 
// Tree query(int start, int end, int l, int r, int ind){
	// Tree res;
	// res.sum = res.max_sum = res.pref = res.suf = INT_MIN;
// 	
	// if(r<start || end <l) return res;
// 	
	// if (l <= start && end <= r) 
		// return tree[ind];
// 		
	// int mid = (start+end)/2;
// 	
	// if(l>mid) return query(mid+1,end,l,r,2*ind+1);
	// if(r<=mid) return query(start,mid,l,r,2*ind);
// 	
	// Tree left = query(start,mid,l,r,2*ind);
	// Tree right = query(mid+1,end,l,r,2*ind+1);
// 	
	// res.sum = left.sum + right.sum;
	// res.pref = max(left.pref,left.sum + right.sum);
	// res.suf = max(left.suf,left.sum + right.suf);
	// res.max_sum = max(res.pref, max(res.suf, max(left.max_sum, max(right.max_sum, left.suf + right.pref))));
// 					
	// return res;
// }
// 
// int main(){
	// ios::sync_with_stdio(0);
	// cin.tie(0);
// 	
	// int t;
	// cin >> t;
	// while(t--){
		// int n,q;
		// cin >> n >> q;
		// int a[n];
		// fo(i,n) cin >> a[i];
		// build(a,0,n-1,1);
		// while(q--){
			// char ch;
			// cin >> ch;
			// if(ch=='U'){
				// int i,val; cin >> i >> val;
				// a[i-1] = val;
				// update(a,0,n-1,1,i-1,val);
			// }else{
				// int l,r;
				// cin >> l >> r;
				// int ans = query(0,n-1,l-1,r-1,1).sum;
				// if(r<n)
				// ans += max(query(0,n-1,l-1,r-1,1).pref,(ll)0);
				// if(l>=2)
				// ans += max(query(0,n-1,l-1,r-1,1).suf,(ll)0);
// 				
				// cout << ans << endl;
			// }
		// }
	// }
// 	
// 	
	// return 0;
// }
// 


#include <bits/stdc++.h> 
using namespace std;
#define lli long long int 
struct node { 
	lli sum, prefixsum, suffixsum, maxsum; 
}; 

node tree[4 * 100009]; 

// function to build the tree 
void build(lli arr[], lli low, lli high, lli  index) 
{ 
	if (low == high) { 
		tree[index].sum = arr[low]; 
		tree[index].prefixsum = arr[low]; 
		tree[index].suffixsum = arr[low]; 
		tree[index].maxsum = arr[low]; 
	} 
	else { 
		lli  mid = (low + high) / 2; 
		
		// left subtree 
		build(arr, low, mid, 2 * index + 1); 
		
		// right subtree 
		build(arr, mid + 1, high, 2 * index + 2); 

		// parent node's sum is the summation 
		// of left and right child 
		tree[index].sum = tree[2 * index + 1].sum + 
						tree[2 * index + 2].sum; 

		// parent node's prefix sum will be equivalent 
		// to maximum of left child's prefix sum or left 
		// child sum + right child prefix sum. 
		tree[index].prefixsum = 
					max(tree[2 * index + 1].prefixsum, 
					tree[2 * index + 1].sum + 
					tree[2 * index + 2].prefixsum); 

		// parent node's suffix sum will be equal to right 
		// child suffix sum or right child sum + suffix 
		// sum of left child 
		tree[index].suffixsum = 
					max(tree[2 * index + 2].suffixsum, 
					tree[2 * index + 2].sum + 
					tree[2 * index + 1].suffixsum); 

		// maxum will be the maximum of prefix, suffix of 
		// parent or maximum of left child or right child 
		// and summation of left child's suffix and right 
		// child's prefix. 
		tree[index].maxsum = 
					max(tree[index].prefixsum, 
					max(tree[index].suffixsum, 
					max(tree[2 * index + 1].maxsum, 
					max(tree[2 * index + 2].maxsum, 
					tree[2 * index + 1].suffixsum + 
					tree[2 * index + 2].prefixsum)))); 
	} 
} 

// function to update the tree 
void update(lli arr[], lli  index, lli low, lli  high, 
			lli idx, lli value) 
{ 
	// the node to be updated 
	if (low == high) { 
		tree[index].sum = value; 
		tree[index].prefixsum = value; 
		tree[index].suffixsum = value; 
		tree[index].maxsum = value; 
	} 
	else { 

		lli mid = (low + high) / 2; 

		// if node to be updated is in left subtree 
		if (idx <= mid) 
			update(arr, 2 * index + 1, low, mid, idx, value); 
		
		// if node to be updated is in right subtree 
		else
			update(arr, 2 * index + 2, mid + 1, 
				high, idx, value); 

		// parent node's sum is the summation of left 
		// and right child 
		tree[index].sum = tree[2 * index + 1].sum + 
						tree[2 * index + 2].sum; 

		// parent node's prefix sum will be equivalent 
		// to maximum of left child's prefix sum or left 
		// child sum + right child prefix sum. 
		tree[index].prefixsum = 
					max(tree[2 * index + 1].prefixsum, 
					tree[2 * index + 1].sum + 
					tree[2 * index + 2].prefixsum); 

		// parent node's suffix sum will be equal to right 
		// child suffix sum or right child sum + suffix 
		// sum of left child 
		tree[index].suffixsum = 
					max(tree[2 * index + 2].suffixsum, 
					tree[2 * index + 2].sum + 
					tree[2 * index + 1].suffixsum); 

		// maxum will be the maximum of prefix, suffix of 
		// parent or maximum of left child or right child 
		// and summation of left child's suffix and 
		// right child's prefix. 
		tree[index].maxsum = 
					max(tree[index].prefixsum, 
					max(tree[index].suffixsum, 
					max(tree[2 * index + 1].maxsum, 
					max(tree[2 * index + 2].maxsum, 
					tree[2 * index + 1].suffixsum + 
					tree[2 * index + 2].prefixsum)))); 
	} 
} 

// fucntion to return answer to every type-1 query 
node query(lli arr[], lli  index, lli low, 
		lli  high, lli  l, lli r) 
{ 
	// initially all the values are INT_MIN 
	node result; 
	result.sum = result.prefixsum = 
				result.suffixsum = 
				result.maxsum = INT_MIN; 

	// range does not lies in this subtree 
	if (r < low || high < l) 
		return result; 

	// complete overlap of range 
	if (l <= low && high <= r) 
		return tree[index]; 

	lli  mid = (low + high) / 2; 

	// right subtree 
	if (l > mid) 
		return query(arr, 2 * index + 2, 
					mid + 1, high, l, r); 
		
	// left subtree	 
	if (r <= mid) 
		return query(arr, 2 * index + 1, 
					low, mid, l, r); 

	node left = query(arr, 2 * index + 1, 
					low, mid, l, r); 
	node right = query(arr, 2 * index + 2, 
						mid + 1, high, l, r); 

	// finding the maximum and returning it 
	result.sum = left.sum + right.sum; 
	result.prefixsum = max(left.prefixsum, left.sum + 
						right.prefixsum); 
							
	result.suffixsum = max(right.suffixsum, 
					right.sum + left.suffixsum); 
	result.maxsum = max(result.prefixsum, 
					max(result.suffixsum, 
					max(left.maxsum, 
					max(right.maxsum, 
					left.suffixsum + right.prefixsum)))); 
					
	return result; 
} 

// Driver Code 
int main() 
{  lli t,n,i,k,l,r,ans,index,value;
char ch;
cin>>t;
while(t--)
{
    cin>>n>>k;
    lli  a[n];
for(i=0;i<n;i++)
{cin>>a[i];
}
	// build the tree 
	build(a, 0, n - 1, 0); 
while(k--)
{
        cin>>ch;
        if(ch=='Q')
        {cin>>l>>r;
        ans=0;
        ans=query(a,0,0,n-1,l-1,r-1).sum;
        if(r<n)
        {
            ans+=max(query(a,0,0,n-1,r,n-1).prefixsum,(lli)0);
        }
        if(l>=2)
        {ans+=max(query(a,0,0,n-1,0,l-2).suffixsum,(lli)0);
        }
        cout<<ans<<"\n";

}


else
{cin>>index>>value;
a[index-1]=value;
update(a, 0, 0, n - 1, index - 1, value); 
}
}
}
}


