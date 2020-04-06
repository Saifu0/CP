#include<bits/stdc++.h>
using namespace std;

int main(){
		int n;
		cin >> n;
		for(int i=0;i<n;i++)
		{
			string s;
			getline(cin , s);
			int pos1 = s.find("+");
			string s1 = s.substr(0, pos1-1);
			int pos2 = s.find("=");
			string s2 = s.substr(pos1+2, (pos2-1) - (pos1+2));
			string s3 = s.substr(pos2+2,s.length());
			
			
			if(s1.find("m") != string::npos){
				cout << stoi(s3) - stoi(s2) << " + " << stoi(s2) << " = " << stoi(s3) << "\n";
			}else if(s2.find("m") != string::npos){
				cout << stoi(s1) << " + " << stoi(s3) - stoi(s1) << " = " << stoi(s3) << "\n";
			}else{
				cout << stoi(s1) << " + " << stoi(s2)  << " = " << stoi(s1) + stoi(s2) << "\n";
			}
		}
		
		
		
}
