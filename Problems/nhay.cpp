#include<bits/stdc++.h>
using namespace std;

#define deb(x) cout << #x << " " << x << endl;
#define fo(i,n) for(int i=0;i<n;i++)
#define Fo(i,k,n) for(int i=k;i<n;i++)
#define vi vector<int>
#define ii pair<int,int>
#define vii vector<ii>
#define ll long long
#define pb push_back
#define endl "\n"
#define mp map<int,int>

int* getLps(string pattern){
	int n = pattern.length();
	int*arr = new int[n];

	arr[0] = 0;

	int i=1,j=0;
	while(i<n){
		if(pattern[i] == pattern[j]){
			arr[i] = j+1;
			i++;
			j++;
		}else{
			if(j!=0){
				j = arr[j-1];
			}else{
				arr[i] = 0;
				i++;
			}
		}
	}
	return arr;
}

int kmp(string text, string pattern){
	int n = text.length();
	int m = pattern.length();

	int count=0,i=0,j=0;

	int*lps = getLps(pattern);
	while(i<n && j<m){
		if(text[i]==pattern[j]){
			i++;
			j++;
		}else{
			if(j!=0){
				j = lps[j-1];
			}else{
				i++;
			}
		}
	}
	if(j==m){
		return i-j;
	}else{
		return -1;
	}
}



int main(){
	int n;
	cin >> n;
	string pattern;
	getline(cin ,pattern);
	getline(cin ,pattern);
	string text;
	getline(cin,text);
	int count = 0;
	for(int i=0;i<text.length();i++){
		int ans = kmp(text,pattern);

		if(ans == -1){
			break;
		}else{
			cout << ans << endl;
			count++;
			text[ans] = '$';
		}
	}
	if(count==0)
		cout << endl << endl;
	
	return 0;
}


