#include<bits/stdc++.h>
using namespace std;

long long n , m , q , x , y, tem1, tem2 , t, sum, mod = 1e9 + 7, ans;

int vis[1001][1001];
int arr[1001][1001];

long long factorial[1000000 + 1];

int dirc [8][2] = { {2 , 1}, {2 , -1}, {-2 , 1}, {-2, -1}, {1 , 2}, {1 , -2}, {-1, 2}, {-1, -2} };

void pre_calculate(){
	factorial[0] = 1;
	for(int i=1;i<1e6;i++){
		factorial[i] = (factorial[i-1]*i)%mod;
	}
}

void dfs(int x, int y){

    vis[x][y] = true;
    sum++;

    for(int i = 0; i < 8; i++){                     // check for the 8 movements

        int dx = x + dirc[i][0];
        int dy = y + dirc[i][1];

        if(dx <= 0 || dx > n || dy <= 0 || dy > m) continue;        // out of board
        if(vis[dx][dy] || !arr[dx][dy]) continue;                   // check if the cell is visited or doesn't contain a horse
        dfs(dx, dy);

    }

}

int main(){
	pre_calculate();

	cin >> t;
	while(t--){
		cin >> n >> m >> q;
		int ans = 1;

		for(int i=0;i<=n;i++){
			for(int j=0;j<=m;j++){
				vis[i][j] = false;
				arr[i][j] = false;
			}
		}

		for(int i=0;i<q;i++){
			int temp1,temp2;
			cin >> temp1 >> temp2;
			arr[temp1][temp2] = true;
		}

		for(int i=0;i<=n;i++){
			for(int j=0;j<=m;j++){
				if(!vis[i][j] && arr[i][j]){
					sum = 0;
					dfs(i,j);

					ans = (ans * factorial[sum])%mod;
				}
			}
		}
		cout << ans << endl;
	}

}