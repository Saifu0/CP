#include<bits/stdc++.h>
#define MAX 1000001
using namespace std;

int* tellme(){
	int* arr = new int[MAX];

	for(int i=2;i<=MAX;i++){
		arr[i] = i;
	}

	for(int i=2;i*i*i<=MAX;i++){
		if(arr[i] != -1){
			for(int j=1;i*i*i*j<=MAX;j++){
				arr[i*i*i*j] = -1;
			}
		}
	}
    
    int* arr1 = new int[MAX];
    int k = 1;
    for(int i=1;i<=MAX;i++){
        if(arr[i] != -1){
            arr1[i] = k++;
        }else{
            arr1[i] = -1;
        }
    }
	return arr1;
}

int main(){
	int t;
	cin >> t;
	int x = t;
	int* arr = tellme();
	arr[1] = 1;
	while(t--){
		int n;
		cin >> n;
		cout << "Case " << x-t << ":" ;
		if( arr[n] == -1){
			cout << "Not Cube Free" << endl;
		}else{
			cout << arr[n] << endl;
		}
	}
}