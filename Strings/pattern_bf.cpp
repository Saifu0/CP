#include<bits/stdc++.h>
using namespace std;

int search(string s1, string s2){
	int l = s1.length();
	int m = s2.length();

	int curr = -1, start = 0;
	for(int i=0;i<l;i++){
		if(s1[i] == s2[start]){
			curr = i;
			for(int j=i;j<i+m;j++){
				if(s1[j] != s2[start]){
					start = 0;
					curr = -1;
					break;
				}else{
					start+=1;
				}
			}
		}
	}
	return curr;
}

int main(){
	string s1,s2;
	cin >> s1 >> s2;

	cout << "String is at " << search(s1,s2) << endl;
}