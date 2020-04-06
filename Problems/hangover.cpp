#include<bits/stdc++.h>
using namespace std;

int main(){
	float c;
	scanf("%f",&c);
	while(c){
		float len = 0.0;
		int n=0;
		while(len < c){
			n++;
			len += 1.00/(1.00+n);
		}
		cout << n << "card(s)" << "\n";
		scanf("%f",&c);
	}
}