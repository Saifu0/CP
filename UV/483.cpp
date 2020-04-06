#include<bits/stdc++.h>
using namespace std;

int main(){
	string s;
	getline(cin , s);
	
	vector<char> v;
	int ind = 0;
	int j=-1;
	for(int i=0;i<s.length();i++){
		if(s[i] == ' ' || i==s.length()-1){
			j = i;
			if(i==s.length()-1)
				j++;
			j-=1;
			while(s[j] != ' '&& j!=-1){
				v.push_back(s[j]);
				j--;	
			}
			v.push_back(' ');
			
		}
	}

	for(int i=0;i<v.size();i++){
		cout << v[i];
	}

}
