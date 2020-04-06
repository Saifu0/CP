#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin >> n;
	while(n!=0){
		int ans = (int)floor(log2(n));
		cout << ans << endl;
		cin >> n;
	}
}
