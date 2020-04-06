#include<bits/stdc++.h>
#define MAX 1000001
using namespace std;

int main(){
	bool arr[MAX+10];

	for(int i=2;i<MAX;i++){
		arr[i] = true;
	}
	arr[0] = arr[1] = false;
	for(int i=2;i<1000;i++){
		if(arr[i]){
			for(int j=i*i;j<MAX;j+=i)
				arr[j] = false;
		}
	}

	int q;
	cin >> q;
	while(q--){
		int a,b,n;
		cin >> a >> b >> n;
		int count = 0,pcount=0;
		if(n==0){
			if(a==1) cout << "1\n";
			else cout << "0\n";
		}else if(n==1){
			for(int j=a;j<=b;j++){
				if(arr[j]) count++;
				
			}
			printf("%d\n", count);
		}else{
			for(int j=a;j<=b;j++){
				pcount = 0;
				for(int k=2;k<=j/2 && pcount<=n;k++){
					if(arr[k]) {
						if(j%k==0)
						pcount++;
					}

				}
				if(pcount == n) count++;
			}
			cout << count << "\n";
		}
	}

	return 0;
}