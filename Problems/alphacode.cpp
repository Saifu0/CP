#include<bits/stdc++.h>
using namespace std;

int alphacode(string s, int n){
	if(n==0){
		return 1;
	}
	if(n==1){
		return 1;
	}

	int smallAns1 = alphacode(s, n-1);

	if((s[n-2]-'0')*10 + (s[n-1]-'0') <= 26){
		smallAns1 += alphacode(s, n-2);
	}
	return smallAns1;
}

int alphacodeDP(string s, int n){
	int* dp = new int[n];
	memset(dp,0,sizeof(n));
	dp[0] = 1;
	

	for(int i=1;i<n;i++){
		dp[i] = dp[i-1];
		if((s[i-1]-'0')*10 + (s[i]-'0') <= 26){
			dp[i] += dp[i-2<0 ? 0 : i-2];
		}
	}
	return dp[n-1];
}

int main(){
	string s;
	cin >> s;
	int n = s.length();
	cout << alphacodeDP(s,n) << endl;
}