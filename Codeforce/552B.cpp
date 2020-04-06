#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin >> n;
	set<int> sr;
	int*arr = new int[n];
	for(int i=0;i<n;i++){
		cin >> arr[i];
		sr.insert(arr[i]);
	}
	
	vector<int> s;
	for(auto i=sr.begin();i!=sr.end();i++)
		s.push_back(*i);

	int ans;
	
	if(s.size() > 3) cout << -1 << endl;
	else if(s.size() == 3){
		int lhs =abs(s[0] - s[1]);
	       	int rhs = abs(s[1] - s[2]);
		if(lhs == rhs)
			cout << lhs << endl;
		else
			cout << -1 << endl;	
	}else if(s.size() == 2){
		int r = abs(s[0] - s[1]);
		if(r%2)
			cout << r << endl;
		else
			cout << r/2 << endl;
	}

}
