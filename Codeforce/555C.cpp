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

struct ans {
	int d;
	char c;
};

int main(){
	int n;
	cin >> n;
	vector<int> arr;
	fo(i,n){
		int data;
		cin >> data;
		arr.pb(data);
	}

	string res;
	int l=0,r=n-1;
	int lst=0;

	while(l<=r){
		vector<pair<int, char> > curr;
		if(lst < arr[l]) curr.pb(make_pair(arr[l],'L'));
		if(lst < arr[r]) curr.pb(make_pair(arr[r],'R'));
		sort(curr.begin(),curr.end());

		if(int(curr.size()) == 2){
			curr.pop_back();
		}

		if(int(curr.size()) == 1){
			if(curr[0].second == 'L'){
				res += 'L';
				lst = arr[l];
				++l;
			}else{
				res += 'R';
				lst = arr[r];
				--r;
			}
		}else{
			break;
		}
	}
	
	cout << res.size() << endl << res << endl;
	
	return 0;
}


