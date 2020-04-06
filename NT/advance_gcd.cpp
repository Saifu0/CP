#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin >> t;
	while(t--){
		int a;
		string b;
		cin >> a >> b;

		int d = 0;

		for(int i=0;i<b.length();i++){
			d = ((d*10)%a + b[i]-'0')%a;
		}

		cout << __gcd(a,d) << endl;
	}
	
}