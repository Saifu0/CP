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
	while(n!=0){
		int*arr = new int[n+1];
		Fo(i,1,n+1){
			cin >> arr[i];
			
		}
		

		int flag = 0;
		Fo(i,1,n+1){
			if(arr[arr[i]] != i){
				flag = 1;
			}
		}

		if(flag == 0)
			cout << "ambiguous" << endl;
		else
			cout << "not ambiguous" << endl;
		cin >> n;
	}
	
	return 0;
} 


