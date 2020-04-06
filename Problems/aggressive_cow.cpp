#include<bits/stdc++.h>
using namespace std;

bool check(int n, int mid, int c, int* arr){
	int curr = arr[0];
	int count = 1;

	for(int i=1;i<n;i++){
		if(arr[i]-curr >= mid){
			count++;
			curr = arr[i];
		}

		if(count == c) return true;
	}
	return false;
}

int main(){
	int n,c;
	cin >> n >> c;
	int* arr = new int[n];

	for(int i=0;i<n;i++)
		cin >> arr[i];

	sort(arr, arr+n);

	int min = arr[0];
	int max = arr[n-1] - arr[0];
	int ans = -1;

	while(min <= max){
		int mid = min + (max-min)/2;
		if(check(n,mid,c,arr)){
			ans = mid;
			min = mid + 1;
		}else{
			max = mid-1;
		}
	}

	cout << ans << endl;
}