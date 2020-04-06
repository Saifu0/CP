#include<bits/stdc++.h>
using namespace std;

string days[] = {"sun","mon","tues","wed","thur","fri","sat"};

int main(){
	int f,r,c;
	cin >> f >> r >> c;
	int i=0;
	int max = INT_MIN;
	int full = min({f/3,r/2,c/2});
	f -= full*3;
	r -= full*2;
	c -= full*2;
	while(i<7){
		int x=f,y=r,z=c;
		int j = i;
		int cnt=0;
		while(x!=0 || y!=0 ||  z!=0){
			if((days[j] == "sun" || days[j] == "mon" || days[j] == "thur") && x!=0) x--;
			else if((days[j] == "tues" || days[j] == "sat") && y!=0) y--;
			else if((days[j] == "wed" || days[j] == "fri") && z!=0) z--;
			else break;
			j = (j+1)%7;
			cnt++;
		}
		if(max < cnt) max = cnt;
		i++;
	}
	cout << max + full*7 << endl;

}
