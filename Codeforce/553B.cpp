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
	int r,c;
	cin >> r >> c;
	int**mat = new int*[r];
	int check=0;
	for(int i=0;i<r;i++){
		mat[i] = new int[c];
		fo(j,c){
			cin >> mat[i][j];
		}
		check ^= mat[i][0];
	}

	if(check){
		cout << "TAK" << endl;
		for(int i=0;i<r;i++)
			cout << 1 << " ";
		return 0;
	}else{
		fo(i,r){
			fo(j,c){
				if(mat[i][j] != mat[i][0]){
					cout << "TAK" << endl;
					fo(k,r){
						if(k==i){
							cout << j+1 << " ";
						}else{
							cout << 1 << " ";
						}
					}
					cout << endl;
					return 0;
				}
			}
		}
			
	}
	cout << "NIE" << endl;



	
	return 0;
}


