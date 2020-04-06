#include<bits/stdc++.h>
using namespace std;

string merge(string s1, string s2){
	int n=s1.length();
	int m=s2.length();

	string res="";
	for(int i=0,j=0;i<n-1&&j<m-1;i++,j++){
		if(s1[i] != s2[i]) break;
		res += s1[i];
	}
	return res;
}

string solve(vector<string> v,int s,int e){
	if(s==e) return v[s];

	if(s<e){
		int mid = s + (e-s)/2;
		string s1 = solve(v,s,mid);
		string s2 = solve(v,mid+1,e);

		return merge(s1,s2);
	}
}

int main(){
	int n;
	cin >> n;
	vector<string> v(n);
	for(int i=0;i<n;i++){
		cin >> v[i];
	}
	cout << solve(v,0,n-1) << endl;
}
