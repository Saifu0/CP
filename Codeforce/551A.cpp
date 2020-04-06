#include<bits/stdc++.h>
using namespace std;

struct node {
	int x,y;
};

int main(){
	int b,t;
	cin >> b >> t;
	int ans;
	int min = INT_MAX;
	node n[b+1];

	for(int i=1;i<=b;i++)
		cin >>n[i].x >> n[i].y; 

	//int min = INT_MAX;
	int flag=0;

	while(1){
		for(int i=1;i<=b;i++){
			if(n[i].x == t){
				flag = 1;
				cout << i << endl;
				break;
			}
		}
		if(flag == 1) break;

		for(int i=1;i<=b;i++){
			while(1){
			if(n[i].x < t){
				n[i].x += n[i].y;
			}else{
				break;
			}
		}
		}

		for(int i=1;i<=b;i++){
			if(n[i].x - t < min){
				min = n[i].x - t;
				ans = i;
			}
		}
		if(min != INT_MAX){
			cout << ans << endl;
			break;
		}
	}
}
