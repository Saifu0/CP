#include<bits/stdc++.h>
using namespace std;

struct node {
	int x,y,ct;
};

bool compare(node a, node b){
	if(a.x == b.x) return a.y < b.y;
	return a.x < b.x;
}

void update(int y, int* bit){
	for(;y<=100000;y+=(y&(-y))){
		bit[y]++;
	}
}

int query(int y, int* bit){
	int count = 0;
	for(;y>0;y-=(y&(-y))){
		count += bit[y];
	}
	return count; 
}

int main(){
	int n;
	cin >> n;
	node* arr = new node[n];
	

	for(int i=0;i<n;i++){
		cin >> arr[i].x >> arr[i].y;
		arr[i].ct = i;
	}
	sort(arr,arr+n,compare);

	int* bit = new int[100001];
	int* ans = new int[n];

	

	for(int i=0;i<n;){

		int end = i;
		while(end < n && arr[i].x == arr[end].x && arr[i].y == arr[end].y){
			end++;
		}

		for(int j=i;j<end;j++){
			ans[arr[j].ct] = query(arr[j].y, bit);

		}

		for(int j=i;j<end;j++){
			update(arr[j].y , bit);

		}
		i = end;
		//ans[arr[i].ct] = query(arr[i].y, bit);
		//update(arr[i].y , bit);
	}

	for(int i=0;i<n;i++){
		cout << ans[i] << endl;
	}
}