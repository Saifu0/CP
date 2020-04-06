#include<bits/stdc++.h>
using namespace std;

void post_to_infix(string s){
	stack<string> stk;
	for(int i=0;i<s.length();i++){
		if(s[i] >= 'a' && s[i] <= 'z'){
			string op(1, s[i]);
			stk.push(op);
		}else{
			string s1 = stk.top();
			stk.pop();
			string s2 = stk.top();
			stk.pop();
			string s3 = "(" + s2 + s[i] + s1 + ")";
			stk.push(s3);
		}
	}
	cout << stk.top() << endl;
}

int main(){
	string s;
	cin >> s;
	post_to_infix(s);
	cout << endl;
}