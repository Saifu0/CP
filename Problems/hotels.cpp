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
	int n,M;
	cin >> n >> M;
	int*arr = new int[n];

	fo(i,n)
		cin >> arr[i];

	int max_so_far=0;
	int curr_max=0;
	int start,j=0;
	fo(i,n){
		start=i;
		while(M>=curr_max+arr[j] && j<n){
			curr_max += arr[j];
			j++;
		}
		if(max_so_far<curr_max)
			max_so_far = curr_max;

		curr_max -= arr[start];
	}

	cout << max_so_far << endl;
	
	return 0;
}


