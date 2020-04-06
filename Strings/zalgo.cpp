#include<bits/stdc++.h>
using namespace std;

void zalgo(string s1, string s2){
	string s = s2 + "$" + s1;
	int*arr = new int[s.length()]();
	int n = s.length();
	int l=0,r=0;
	for(int i=1;i<n;i++){
		if(i>r){
			l = i, r = i;
			while(r < n && s[r-l] == s[r]) r++;
			arr[i] = r-l;
			r--;
		}else{
			int k = i-l;
			if(arr[k]<=r-i){
				arr[i] = arr[k];
			}else{
				l = i;
				while(r < n && s[r-l] == s[r]) r++;
				arr[i] = r-l;
				r--;
			}
		}
	}

	for(int i=0;i<n;i++){
		if(arr[i] == s2.length()){
			cout << i - (s2.length() + 1) << endl;
		}
	}
}

int main(){
	string s1,s2;
	cin >> s1 >> s2;

	zalgo(s1,s2);
}