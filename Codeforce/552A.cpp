#include<bits/stdc++.h>
using namespace std;

int main(){
	int a,b,c,d;
	cin >> a >> b >> c >> d;
	vector<int> v(4);
	v[0] = a;
	v[1] = b;
	v[2] = c;
	v[3] = d;
	sort(v.begin(),v.end());;

	int z = v[3] - v[0];
	int y = v[1] - z;
	int x = v[0] - y;

	cout << x << " " <<  y << " " <<  z << endl;
}
