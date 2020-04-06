#include<bits/stdc++.h>
using namespace std;

long long merge(int*arr, int l, int r , int mid){
	int i=l,j=mid,k=0;
	int temp[r-l+1];
	long long count = 0;

	while(i<mid && j<=r){
		if(arr[i] <= arr[j]){
			temp[k++] = arr[i++];
		}else{
			temp[k++] = arr[j++];
			count += mid-i;
		}
	}
	while(i<mid){
		temp[k++] = arr[i++];
	}
	while(j<=r){
		temp[k++] = arr[j++];
	}
	for(int i=l,k=0;i<=r;i++,k++){
		arr[i] = temp[k];
	}
	return count;
}

long long solve(int*arr, int start, int end){
	int count = 0;
	if(start<end){
			int mid = (start+end)/2;
			long long ans1 = solve(arr, start, mid);
			long long ans2 = solve(arr, mid+1, end);
			
			long long ans3 = merge(arr, start, end, mid+1);
			return ans1 + ans2 + ans3;
	}
	return count;
	
}

int main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		int* arr = new int[n];
		for(int i=0;i<n;i++){
				cin >> arr[i];
		}
		
		cout << solve(arr, 0, n-1) << endl;
	}
}
