#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin >> n;
	while(n){
		int*arr = new int[n];
		stack<int> s;
		int curr = INT_MAX;
		for(int i=0;i<n;i++){
			cin >> arr[i];
			if(curr > arr[i])
				curr = arr[i];
		}

		int i=0;
		
		while(true){
			if(arr[i] == curr){
				//cout << curr << " ";
				curr += 1;
				i++;

			}else if(!s.empty() && curr == s.top()){
				//cout << curr << " ";
				
				s.pop();
				curr += 1;
			}else if(i<n && arr[i] != curr ){
				//cout << curr << " ";
				
				s.push(arr[i]);
				i++;
			}
			else{
				break;
			}
		}

		// while(!s.empty()){
		// 	cout << s.top() << " ";
		// 	s.pop();
		// }
		//cout << i << endl;
		if(i==n && s.empty()) cout <<"yes" << "\n";
		else cout << "no" << "\n";

		cin >> n;
	}
}