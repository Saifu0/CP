#include<bits/stdc++.h>
using namespace std;

int* lps(string s){
	int j=0;
	int len = s.length();
	int* arr =  new int[len];

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

	return arr;
}

bool kmp(string text, string pattern){
	int lenText = text.length();
	int lenPat = pattern.length();

	int i=0,j=0;

	int* lp = lps(pattern);

	while(i<lenText && j<lenPat){
		if(text[i] == pattern[j]){
			i++;
			j++;
		}else{
			if(j!=0){
				j = lp[j-1];
			}else{
				i++;
			}
		}
	}

	if(j==lenPat) return true;
	return false;
}

int main(){
	string s1,s2;
	cin >> s1 >> s2;
	cout << kmp(s1,s2) << endl;
}