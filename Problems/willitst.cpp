#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin >> n;

	if(n>1 && ceil(log2(n)) == floor(log2(n)))
		cout << "TAK\n";
	else
		cout << "NIE\n";
}