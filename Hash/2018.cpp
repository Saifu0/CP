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

struct Ride {
	int a,b,x,y,s,f,sd;
};

vector<vi> solve(Ride* R, int row, int col, int val, int n, int b){
	int min = INT_MAX;

	fo(i,n){
		if(R[i].sd < min)
			min = R[i].sd;
	}
	
}

int main(){
	int r,c,v,n,b,t;
	


	Ride*R= new Ride[n];

	string input_path = "input.in";
	string output_path = "output.out";


	auto hi = freopen(input_path.c_str(), "r", stdin);
	cin >> r >> c >> v >> n >> b >> t;
	fo(i,n){
		 cin >> R[i].a >> R[i].b >> R[i].x >> R[i].y >> R[i].s >> R[i].f;
		 R[i].sd = (abs(R[i].x-R[i].a) + abs(R[i].y-R[i].b)) + R[i].s + (abs(R[i].a) + abs(R[i].b));
		 //cout << R[i].sd;
	}

	vector<vi> ans =  solve(R,r,c,v,n,b);

	auto out = fopen(output_path.c_str(), "w");

	fo(i,n){
		 fprintf(out, "%d ", R[i].sd);
	}
	fprintf(out,"\n");
	fclose(out);


	
	return 0;
}


