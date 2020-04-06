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
	int n,k;
	cin >> n >> k;
	vector<int> ans(k);

	int ind = k;
	int i=0;
	if(k!=1){
		ans.pb(1);
		n -= 1;
		ind--;
	}else{
		ans.pb(n);
		n = 0;
	}
	int flag=0;
	while(n!=0){
		int temp = ans[i];
		if(2*temp < n && ind > 0 && (n-2*temp) >= ind){
			ans.pb(2*temp);
			i++;
			n -= 2*temp;
		}else if(2*temp > n && ind > 0 && (n-(temp+1)) >= ind){
			ans.pb(2*temp);
			i++;
			n -= (temp+1);
		}else if(n <= 2*temp && ind==0){
			ans.pb(n);
			i++;
			n = 0;
		}else{
			flag=1;
			break;
		}
	}

	for(auto i: ans){
		cout << i << " ";
	}
	cout << endl;
	
	return 0;
}


