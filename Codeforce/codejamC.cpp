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
#define F first
#define S second
#define sz(v) (int)v.size()
#define mod 1000000007

void c_p_c()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}

struct job {
	int f,s,ind;
};

bool cmp(job a, job b){
	return a.f < b.f;
}

int main(){
	c_p_c();
	int t; cin >> t;
	int start = 1;
	while(t--){
		int n; cin >> n;
		job a[n];
		fo(i,n){
			cin >> a[i].f >> a[i].s;
			a[i].ind = i;
		}
		sort(a,a+n,cmp);

		bool C = true ;
		int c=0,j=-1;
		bool vis[n+1] = {false};
		std::vector<char> ans(n);
		bool f = false;
		// fo(i,n){
		// 	if((C && !vis[i] && i==0) || (C && !vis[i] && c<=a[i].f)){
		// 		ans[a[i].ind] = 'C';
		// 		c = a[i].s;
		// 		vis[i] = true;
		// 		C = false;
		// 	}else if((!C && j==-1 && !vis[i]) || (!C && !vis[i] && j<=a[i].f )){
		// 		ans[a[i].ind] = 'J';
		// 		j=a[i].s;
		// 		vis[i] = true;
		// 		C = true;
		// 	}else if(i>0 && !vis[i] && !f){
		// 		i--;
		// 		C = !C;
		// 		f = true;
		// 	}else{
		// 		break;
		// 	}
		// }

		fo(i,n){
			if((!vis[i] && i==0) || (!vis[i] && c<=a[i].f)){
				c = a[i].s;
				vis[i] = true;
				ans[a[i].ind] = 'C';
				fo(k,n){
					if(!vis[k] && c<=a[k].f){
						vis[k] = true;
						c = a[k].s;
						ans[a[k].ind] = 'C';
					}
				}
			}
			if((!vis[i] && j==-1) || (!vis[i] && j<=a[i].f)){
				j = a[i].s;
				vis[i] = true;
				ans[a[i].ind] = 'J';
				fo(k,n){
					if(!vis[k] && j<=a[k].f){
						vis[k] = true;
						j = a[k].s;
						ans[a[k].ind] = 'J';
					}
				}
			}
		}
		bool flag = false;
		for(int i=0;i<n;i++){
			if(!vis[i]){
				flag = true;
			}
		}
		if(flag){
			cout << "Case #" << start++ << ": " << "IMPOSSIBLE"	 << endl;
			continue;
		}
		cout << "Case #" << start++ << ": ";
		fo(i,sz(ans)) cout << ans[i];
		cout << endl;

	}

	return 0;
}