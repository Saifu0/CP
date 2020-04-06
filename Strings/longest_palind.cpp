#include<bits/stdc++.h>
using namespace std;

int main(){
	string s;
	cin >> s;
	int max = 1;
	int l,r;
	int n = s.length();
	for(int i=1;i<n;i++){
		l=i-1,r=i;
		while(l>=0 && r<n && s[l] == s[r]){
				if(max < r-l+1){
					max = r-l+1;
				}
				l--;
				r++;
		}

		l = i-1;
		r = i+1;
		

		while(l>=0 && r <n && s[l] == s[r]){
			if(r-l+1 > max){
				max = r - l + 1;
			}
			l--;
			r++;
		}
	}

	cout << max << endl;
}