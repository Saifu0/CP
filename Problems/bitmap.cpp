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

int a[190][190];
int n , m;

void BFS(char x, char y){
	queue<char> q;
	q.push(x);
	q.push(y);

	a[x][y] = 0;

	while(!q.empty()){
		int i = q.front();
		q.pop();
		int j = q.front();
		q.pop();

		int dist = a[i][j] + 1;


		if(j-1>=0 && dist < a[i][j-1]){
			q.push(i);
			q.push(j-1);
			a[i][j-1] = dist;
		}
		if(i-1>=0 && dist < a[i-1][j]){
			q.push(i-1);
			q.push(j);
			a[i-1][j] = dist;
		}
		if(j+1<m && dist < a[i][j+1]){
			q.push(i);
			q.push(j+1);
			a[i][j+1] = dist;
		}
		if(i+1<n && dist < a[i+1][j]){
			q.push(i+1);
			q.push(j);
			a[i+1][j] = dist;
		}
	}
}

int main(){
	int t;
	cin >> t;
	while(t--){
		vii vc;
		cin >> n >> m;

		fo(i,n){
			fo(j,m){
				char ch;
				cin >> ch;
				if(ch == '1'){
					a[i][j] = INT_MIN;
					vc.pb(make_pair(i,j));
				}else{
					a[i][j] = INT_MAX;
				}
			}
		}
		for(int i=0;i<vc.size();i++){
			BFS(vc[i].first, vc[i].second);
		}

		fo(i,n){
			fo(j,m){
				cout << a[i][j] << " ";
			}
			cout << endl;
		}


	}
	
	return 0;
}



