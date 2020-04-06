#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		int tot = 0;
		map<int,int> mp;
		for(int i=0;i<n;i++){
			int p,s;
			cin >> p >> s;
			int temp = mp[p]; 
			if(p >= 1 && p <= 8){
				if(temp < s){
					mp[p] = s;
				}else{
					mp[p] = temp;
				}
			}
		}

		for(int it=0;it<sizeof(mp);it++){
			tot += mp[it];
		}

		cout << tot << endl;
	}
}