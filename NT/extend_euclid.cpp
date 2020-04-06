#include<bits/stdc++.h>
using namespace std;

class Triplet {
public:
	int x,y,ans;
};

Triplet extendEuclid(int a,int b){

	if(b==0){
		Triplet answer;
		answer.ans = a;
		answer.x = 1;
		answer.y = 0;
		return answer;
	}

	Triplet smallAns = extendEuclid(b,a%b);
	Triplet answer;

	answer.ans = smallAns.ans;
	answer.x = smallAns.y;
	answer.y = smallAns.x - (a/b)*smallAns.y;

	return answer;
}

int main(){
	int a=16,b=10;
	Triplet answer = extendEuclid(a,b);
	cout << answer.ans << "\n";
	cout << answer.x << "\n";
	cout << answer.y << "\n";

}