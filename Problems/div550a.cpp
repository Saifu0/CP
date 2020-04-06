#include<bits/stdc++.h>
using namespace std;

int main(){
	int q;
	cin >> q;
	while(q--){
		string s;
		cin >> s;
		
		if(set<char>(s.begin(), s.end()).size() == s.length() && 
			*max_element(s.begin(),s.end()) == char(*min_element(
				s.begin(),s.end()) + s.length() -1)){
			cout << "Yes" <<endl;
		}else{
			cout << "No" << endl;
		}
	}
}