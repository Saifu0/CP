#include<bits/stdc++.h>
using namespace std;

#define deb(x) cout << #x << " " << x << endl;
#define fo(i,n) for(int i=0;i<n;i++)
#define Fo(i,k,n) for(int i=k,i<n;i++)
#define vi vector<int>
#define ii pair<int,int>
#define vii vector<ii>
#define ll long long
#define pb push_back
#define endl "\n"
#define mp map<int,int>


int solve(int n, map<int,string> mps, string* out){
	if(n==0){
		out[0] = "";
		return 1;
	}
	
	int small = n%10;
	int smallSize = solve(n/10,mps,out);
	string s = mps[small];
	
	fo(i,s.size()-1){
		fo(j,smallSize){
			out[j + (i+1)*smallSize] = out[j];
		}
	}
	int k=0;
	fo(i,s.size()){
		fo(j,smallSize){
			out[k] = out[k] + s[i];
			k++;
		}
	}
	return smallSize*s.size();
}


int main(){
	int n;
	cin >> n;
	map<int,string> mps;
	mps[1] = "abc";
	mps[2] = "def";
	mps[3] = "ghi";
	mps[4] = "jkl";
	mps[5] = "mno";
	mps[6] = "pqrs";
	mps[7] = "tuv";
	mps[8] = "wxyz";
	
	string* out = new string[1000];
	
	int size = solve(n,mps,out);
	
	fo(i,size) cout << out[i] << endl;
	
	return 0;
}



