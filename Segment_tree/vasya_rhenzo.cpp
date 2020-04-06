// #include<bits/stdc++.h>
// using namespace std;

// struct Node {
// 	int ath, bth,res;
// };

// void buildTree(Node* tree, int* a, int *b, int start, int end, int index){
// 	if(start == end){
// 		tree[index].ath = start;
// 		tree[index].bth = start;
// 		tree[index].res = start;
// 		return;
// 	}

// 	int mid = (start + end)/2;

// 	buildTree(tree, a, b, start, mid, 2*index);
// 	buildTree(tree, a, b , mid+1, end, 2*index+1);

// 	tree[index].ath = a[tree[2*index].ath] > a[tree[2*index+1].ath] ? tree[2*index].ath : tree[2*index+1].ath;
// 	tree[index].bth = b[tree[2*index].bth] < b[tree[2*index+1].bth] ? tree[2*index].bth : tree[2*index+1].bth;
// 	tree[index].res = tree[index].ath;
// 	if(a[tree[2*index].ath] == a[tree[2*index+1].ath]){
// 		tree[index].res = tree[index].bth;
// 	}
// }

// Node query(Node* tree, int*a, int*b, int start, int end, int index, int l ,int r){
// 	Node result;
// 	result.ath = result.bth = result.res = -1;
// 	if(l > end || start > r) return result;


// 	if(start >= l && end <= r) return tree[index];

// 	int mid = (start + end)/2;
// 	Node ans1 = query(tree, a,b,start , mid , 2*index, l , r);
// 	Node ans2 = query(tree, a,b,mid+1, end, 2*index+1, l , r);

// 	result.ath = a[ans1.ath] >  a[ans2.ath] ? ans1.ath : ans2.ath;
// 	result.bth = b[ans1.bth] <  b[ans2.bth] ? ans1.bth : ans2.bth;
// 	result.res = result.ath;
// 	if(a[ans1.ath] ==  a[ans2.ath]){
// 		result.res = result.bth;
// 	}
// 	return result;
// }

// int main(){
// 	int n;
// 	cin >> n;
// 	int a[n],b[n];
// 	for(int i=0;i<n;i++){
// 		cin >> a[i] ;
// 	}
// 	for(int i=0;i<n;i++){
// 		cin >> b[i] ;
// 	}
// 	Node* tree = new Node[4*n];
// 	buildTree(tree, a,b, 0, n-1, 1);

// 	int q;
// 	cin >> q;

// 	for(int i=1;i<2*n;i++){
// 		cout << tree[i].ath << " " << tree[i].bth << " " << tree[i].res << endl;
// 	}

// 	while(q--){
// 		int l,r;
// 		cin >> l >> r;

// 		Node result = query(tree, a,b,0, n-1 ,1, l-1, r-1);
// 		cout << result.res+1 << endl;
// 	}

// 	return 0;
// }

#include <bits/stdc++.h>
using namespace std;

int v[4000002];
int arr[1000002],brr[1000002];
map<int,int>m;

void build(int node,int start,int end)
{
        if(start==end)
        {
                v[node]=start;
        }
        else{
        int mid=(start+end)/2;
        build(2*node,start,mid);
        build(2*node+1,mid+1,end);
        if(arr[v[2*node]]>=arr[v[2*node+1]]){
         if(arr[v[2*node]]>arr[v[2*node+1]])
         v[node]=v[2*node];
         else{
                if(brr[v[2*node]]<=brr[v[2*node+1]])
                {
                        v[node]=v[2*node];
                }
                else v[node]=v[2*node+1];
         }
        }
        else
        {
                v[node]=v[2*node+1];
        }
        }
}

int query(int node,int start,int end,int l,int r)
{
        if(l>end || r<start)
        {
                return -1;
        }
        if(l<=start && r>=end) return v[node];
        else
        {
                int mid=(start+end)/2;
                int v1 = query(2*node,start,mid,l,r);
                int v2 = query(2*node+1,mid+1,end,l,r);
                if(v1==-1 && v2==-1) return -1;
                if(v1==-1 && v2!=-1) return v2;
                if(v2==-1 && v1!=-1) return v1;

                if(arr[v1]>=arr[v2]){
                 if(arr[v1]>arr[v2])
                        return v1;
                 else{
                        if(brr[v1]<=brr[v2])
                        {
                                return v1;
                        }
                        else return v2;
                 }
                }
                else
                {
                        return v2;
                }
        }
}

int main() {
        int a,b,l,r;
        scanf("%d",&a);
        for(int i=0;i<a;i++)
        {
               scanf("%d",&arr[i]);
        }
        for(int i=0;i<a;i++)
        {
                scanf("%d",&brr[i]);
        }
        build(1,0,a-1);
        cin>>b;
        while(b--)
        {
                scanf("%d %d",&l,&r);
                printf("%d\n",query(1,0,a-1,l-1,r-1)+1);
        }
        return 0;
}