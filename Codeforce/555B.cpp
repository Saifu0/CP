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

int main(){
	int n;
	cin >> n;
	string s;
	cin >> s;

	int arr[10];
	vector<int> diff;
	Fo(i,1,10){
		cin >> arr[i];
	}

	for(int i=0;i<n;i++){
		diff.pb(arr[s[i]-'0'] - (s[i]-'0'));
	}

	for(int i=0;i<n;i++){
		if(diff[i] > 0){
			while(i<n && diff[i] >=0){
				s[i] = char(arr[s[i]-'0'] + '0');
				i++;
			}
			break;
		}
	}

	cout << s << endl;
	
	return 0;
}


