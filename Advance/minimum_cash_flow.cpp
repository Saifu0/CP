#include<bits/stdc++.h>
using namespace std;
#define N 3

int getmin(int amt[]){
	int mi = 0;
	for(int i=1;i<N;i++){
		if(amt[i] < amt[mi])
			mi = i;
	}
	return mi;
}

int getmax(int amt[]){
        int mi = 0;
        for(int i=1;i<N;i++){
                if(amt[i] > amt[mi])
                        mi = i;
        }
        return mi;
}

void solve(int amt[]){
	int minC = getmax(amt);
	int minD = getmin(amt);

	if(amt[minC] == 0 && amt[minD]==0) return;

	int mn = min(-amt[minD],amt[minC]);
	amt[minC] -= mn;
	amt[minD] += mn;

	cout << "Person " << minD << " pays " << mn << " to " << "Person " << minC << endl;

	solve(amt);

}

int main(){
	int graph[N][N] = { {0, 1000, 2000}, 
                        {0, 0, 5000}, 
                        {0, 0, 0},}; 
	
	int amt[N] = {0};
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			amt[i] += (-graph[i][j] + graph[j][i] );	
		}
	}
	solve(amt);
}
