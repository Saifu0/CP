#include<bits/stdc++.h>
using namespace std;

const int N = 150010;

int main(){
	int n,k;
	cin >> n >> k;
	int a[N];
	int s[N];
	a[0] = 0;
	s[0] = 0;
	for(int i=1;i<=n;i++){
		cin >> a[i];
		s[i] = s[i-1] + a[i];
	}

	int j=0,ind;
	int min = INT_MAX;
	for(int i=k;i<=n;i++){
		int x = s[i]-s[j]; 
		if(min > x){
			min = x;
			ind = j;
		}
		j++;
	}
	cout << ind+1 << "\n";
}
