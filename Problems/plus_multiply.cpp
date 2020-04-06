#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int n;
		scanf("%d",&n);
		vector<int> v(n);
		for(int i=0;i<n;i++){
			scanf("%d",&v[i]);
		}

		map<int,pair<int,int> > mp;
		int count= 0;
		for(int i=0;i<n;i++){
			for(int j=i+1;j<n;j++){
				int prod = v[i] * v[j] - (v[i] + v[j]);

				if(mp.find(prod) == mp.end()){
					mp[prod] = make_pair(i,j);
				}else{
					count++;
				}
			}
		}
		printf("%d\n",count);
	}

	return 0;
}
