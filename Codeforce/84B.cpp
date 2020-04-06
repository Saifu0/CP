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
#define S second
#define F first

void c_p_c()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}

int main(){
	c_p_c();
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		vector<bool> done(n+1,0);
		int free_girl = 0;

		Fo(i,1,n+1){
			int k; cin >> k;
			int girl = 0;
			while(k--){
				int x; cin >> x;
				if(girl) continue;

				if(done[x]) continue;

				done[x] =1;
				girl = 1;
			}

			if(girl==0) free_girl = i;
		}
		if(free_girl==0){
			cout << "OPTIMAL\n";
		}else{
			cout << "IMPROVE\n";
			cout << free_girl << " ";
			Fo(i,1,n+1){
				if(done[i]== false){
					cout << i << endl;
					break;
				}
			}
		}
	}
	
	return 0;
}
