#include<bits/stdc++.h>
using namespace std;

int addition(int a, int b){
	int count = 0;
	while(b>0){
		int u = a^b;
		int v = a&b;
		a = u;
		b = v*2;
		count++;
	}
	return count;
}

int convert(string x){
	int ans = 0;
	int k=0;
	for(int i=x.length()-1;i>=0;i--){
		ans += (x[i]-'0')*pow(2,k);
		k++;
	}
	return ans;
}

int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		string a,b;
		cin >> a >> b;
		int x = convert(a);
		int y = convert(b);
		//cout << x << " " << y << endl;
		cout << addition(x,y) << endl;
	}
}