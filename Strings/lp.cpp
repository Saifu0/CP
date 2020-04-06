#include<bits/stdc++.h>
using namespace std;

void lps(string s){
	int j=0;
	int arr[s.length()];

	for(int i=0;i<s.length();i++){
		arr[i] = 0;
	}
	int i= 1;
	while(i < s.length()){
		if(s[j] == s[i]){
			arr[i] = j + 1;
			j++;
			i++;
		}else {
			if(j==0){
				i++;
			}else{
				j = arr[j-1];
			}
			
		}
	}

	for(int i=0;i<s.length();i++){
		cout << arr[i] << " ";
	}
}

int main(){
	string s;
	cin >> s;
	lps(s);
}