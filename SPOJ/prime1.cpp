#include<bits/stdc++.h>
using namespace std;

bool isPrime(long int n){
	if(n<=1) return false;
	else if(n==2) return true;
	else if(n%2 == 0) return false;
	else{
		bool prime = true;
		int divisor = 3;
		int upperlimit = sqrt(n) + 1;
		while(divisor <= upperlimit){
			if(n%divisor == 0){
				return false;
			}
			divisor += 2;
		}
		return prime;
	}
}

int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		long int n,m;
		cin >> n >> m;
		for(long int i=n;i<=m;i++){
			if(isPrime(i)){
				cout << i << "\n";
			}
		}
	}
}