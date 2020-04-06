#include<bits/stdc++.h>
using namespace std;

struct entry {
	int v,dist;
};

int solve(int move[], int n){
	bool* vis = new bool[n];
	for(int i=0;i<n;i++) vis[i] = false;

	queue<entry> q;
	vis[0] = true;
	entry s = {0,0};
	q.push(s);

	entry qe;
	while(!q.empty()){
		qe = q.front();
		q.pop();

		int v = qe.v;
		
		if(v==n-1) break;

		for(int i=v;i<=(v+6) && i<n;i++){
			if(!vis[i]){
				entry a;
				a.dist = qe.dist + 1;
				vis[i] = true;

				if(move[i] != -1) a.v = move[i];
				else a.v = i;

				q.push(a);
			}
		}
	}
	return qe.dist;
}

int main(){
	int n=30;
	int move[n];
	for(int i=0;i<n;i++) move[i] = -1;

	move[2] = 21; move[4] = 7; move[10] = 25; move[19] = 28;
	move[26] = 0; move[20] = 8; move[16] = 3; move[18] = 6;

	cout << solve(move,n) << endl;

}
