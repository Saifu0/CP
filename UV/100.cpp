#include<bits/stdc++.h>
using namespace std;

int main(){
	int i,j;
	cin >> i >>j;
	int counti=1,countj=1;
	int flag = 0;
	if(j<i){
	       swap(j,i);
		flag = 1;
	}

	for(int end=i;end<=j;end++){
		int start = end;
		int sum = 1;
		while(start != 1){
			if(start%2 == 1)
				start = 3*start + 1;
			else
				start = start/2;
			sum += 1;
		}
		if(sum > counti){
			counti = sum;
		}
	}
	if(flag == 1)
		swap(i,j);
	cout << i << " " << j << " " << counti << "\n";
}
