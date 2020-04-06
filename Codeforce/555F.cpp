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
	vector<int> a(n);
	fo(i,n) cin >> a[i];

	sort(a.begin(),a.end());

	int max =INT_MIN;
	int start=0,end=0;
	int maxS = start,maxE = 0;
	for(int i=1;i<n;i++){
		if(abs(a[i-1]-a[i]) == 0 || abs(a[i-1]-a[i]) == 1){
			end = i;
			if(max < end-start+1){
				max = end-start+1;
				maxS = start;
				maxE = end;
			}
		}else{
			if(max < end-start+1){
				max = end-start+1;
				maxS = start;
				maxE = end;
			}
			start = i;
			end = i;
		}
	}

	cout << maxE-maxS+1 << endl;

	Fo(i,maxS,maxE+1)
		cout << a[i] << " ";

	cout << endl;
	
	return 0;
}


