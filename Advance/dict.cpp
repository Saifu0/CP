#include<bits/stdc++.h>
using namespace std;

const int N = 12345;

int r=3,c=3;
vector<char> v[N];
string dict[] = {"saifu" ,"guf", "sahil" ,"naved" } ;
int n = 4;
bool vis[3][3] = { { false } };

bool isFound(string s){
	for(int i=0;i<n;i++){
		if(s.compare(dict[i]) == 0) return true; 
	}
	return false;
}

void solve(int x, int y, string s){
	vis[x][y] = true;
	s += v[x][y];

	if(isFound(s)) cout << s << endl;

	for(int i=x-1;i<=x+1 && i<r;i++){
		for(int j=y-1;j<=y+1 && j<c;j++){
			if(i>=0 && j>=0 && !vis[i][j]){
				solve(i,j,s);
			}
		}
	}
	s.erase(s.length()-1);
	vis[x][y] = false;
}

int main(){
	cin >> r >> c; 
	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++){
			cin  >> v[i][j];
		}
	}

//	vis[r][c] =  { { false } };
	
	string str="";
	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++){
			solve(i,j,str);		
		}
	}
}
