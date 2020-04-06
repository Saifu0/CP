#include<bits/stdc++.h>
using namespace std;

int main(){
		int t;
		cin >> t;
		while(t--){
			int g,m;
			cin >> g >> m;
			vector<int> arrg(g);
			vector<int> arrm(m);
			for(int i=0;i<g;i++){
				cin >> arrg[i];
			}
			
			for(int i=0;i<m;i++){
				cin >> arrm[i];
			}
			
			sort(arrg.begin(),arrg.end(), greater<>());
			sort(arrm.begin(),arrm.end(), greater<>());
			
			while(g > 0 && m > 0){
					if(arrg[g-1] == arrm[m-1]){
						arrm.pop_back();
						m--;
					}
					else if(arrg[g-1] > arrm[m-1]){
						arrm.pop_back();
						m--;
					}else{
						arrg.pop_back();
						g--;
					} 
			}
			
			if(g != 0)
				cout << "Godzilla\n";
			else if(m != 0)
				cout << "MechaGodzilla\n";
			else
				cout << "Uncertain\n";
		}
}
