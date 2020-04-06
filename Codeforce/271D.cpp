#include<bits/stdc++.h>
using namespace std;

const int N = 1234567;
const int md = 1000000007;

int s[N],f[N];

int main(){
	int n,k;
	cin >> n >> k;
	f[0] = 1;
	for(int i=1;i<N;i++){
		f[i] = f[i-1];
		if(i>=k){
			f[i] += f[i-k];
			if(f[i] >= md) f[i] -= md;
		}
	}
	s[0];
	for(int i=1;i<N;i++){
		s[i] = s[i-1] + f[i];
		if(s[i] >= md) s[i] -= md;
	}
	while(n--){
		int a,b;
		cin >> a >> b;
		printf("%d\n",(s[b]-s[a-1] + md)%md);
	}
	
}
