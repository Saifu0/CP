#include<bits/stdc++.h>
using namespace std;

int main(){
	int r,c;
	cin >> r >> c;
	char mat[r][c];
	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++){
			cin >> mat[i][j];
		}
	}
	if(c%2==0){
		bool b=true;
		for(int i=0;i<r;i++){
			for(int j=0;j<c;j++){
				if(mat[i][j]=='-'){ b = !b ;continue;}
				if(b) mat[i][j] = 'B', b = !b;
				else mat[i][j] = 'W', b = !b;
			}
			b = !b;
		}
	}else{
		bool b=true;
                for(int i=0;i<r;i++){
                        for(int j=0;j<c;j++){
				if(mat[i][j]=='-'){ b = !b ;continue;}
                                if(b) mat[i][j] = 'B', b = !b;
                                else mat[i][j] = 'W', b = !b;
                        }
                }
	}
	for(int i=0;i<r;i++){
                for(int j=0;j<c;j++){
                        cout << mat[i][j];
                }
		cout << "\n";
        }
}
