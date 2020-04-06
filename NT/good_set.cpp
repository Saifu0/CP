#include<bits/stdc++.h>


using namespace std;

const int MOD = 1e9+7;
const int MAX = 1e6;

int main(){
	int t;
	cin >> t;

	

	while(t--){
		int n;
		cin >> n;
		vector<int> v(MAX,0);

		for(int i=0;i<n;i++){
			int x;
			cin >> x;
			v[x]++;
		}
		for(int i=1;i<=MAX;i++){
			if(v[i] != 0){
				for(int j=2*i;j<=MAX;j+=i){
					if(v[j] != 0)
						v[j] += v[i];
				}
			}
		}
		int ans = 0;
		for(int i=1;i<=MAX;i++){
			ans = (ans + v[i])%MOD;
		}
		cout << ans << endl;
	}
}