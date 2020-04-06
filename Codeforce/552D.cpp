#include<bits/stdc++.h>
using namespace std;

int main(){
	int n,b,a;
	cin >> n >> b >> a;
	int*arr = new int[n];
	for(int i=0;i<n;i++) cin >> arr[i];
	int maxB = b,maxA = a;
	int cnt=0;
	for(int i=0;i<n;i++){
		if(a==0 && b==0) break;
		else if(a==0){
			if(arr[i] == 1) a = min(maxA,a+1);
			b--;
		}else if(b==0){
			a--;
		}else if(arr[i] == 1 && a < maxA){
			a = min(maxA,a+1);
			b--;
		}else
			a--;
		cnt++;
	}
	cout << cnt << endl;
}
