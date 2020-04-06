#include<bits/stdc++.h>
using namespace std;

int main(){
	string s;
	cin >> s;
	int q;
	cin >> q;
	int n = s.size();
	int dp[n];
	for(int i=0;i<n;i++){
		dp[i] = 0;
	}
	for(int i=1;i<n;i++){
		if(s[i-1] == s[i])
			dp[i] = dp[i-1] + 1;
		else
			dp[i] = dp[i-1];
	}
	while(q--){
		int f,s;
		cin >> f >> s;
		int ans1 = dp[s-1];
		int ans2 = dp[f-1];
		cout << ans1 - ans2 << endl;
	}

}
