#include<bits/stdc++.h>
using namespace std;

int precedence(char s){
	if(s=='+' || s=='-'){
		return 1;
	}else if(s=='*' || s=='/'){
		return 2;
	}else{
		return 0;
	}
}

void infix_to_postfix(string s){
	stack<char> stk;
	for(int i=0;i<s.length();i++){
		if(s[i]>='a' && s[i]<='z'){
			cout << s[i];
		}else if(s[i] == '('){
			stk.push(s[i]);
		}
		// else if(stk.empty() || precedence(stk.top()) < precedence(s[i])){
		// 	stk.push(s[i]);
		// }
		else if(s[i] ==')'){
			while(!stk.empty() && stk.top() != '('){
				cout << stk.top();
				stk.pop();
			}
			stk.pop();
		}
		else{
			while(!stk.empty() && precedence(stk.top()) >= precedence(s[i])){
				cout << stk.top();
				stk.pop();
			}
			stk.push(s[i]);
		}
	}
	while(!stk.empty()){
		cout << stk.top();
		stk.pop();
	}
}

int main(){
	string s;
	cin >> s;
	infix_to_postfix(s);
	cout << endl;
}