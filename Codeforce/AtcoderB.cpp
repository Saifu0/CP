#include<bits/stdc++.h>
using namespace std;

#define sc(x) scanf("%d",&x)
#define pf(c) scanf("%d",x);
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

bool isPalindrome(string str, int l, int h) 
{ 
 
    while (h > l) 
    { 
        if (str[l++] != str[h--]) 
        { 
            return false;
        } 
    } 
    return true;
} 

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	string s;
	cin >> s;
	
	int n = s.length();
	
	//bool flag = false;
	
	int first = (n-1)/2 - 1;
	int last = (n+3)/2 - 1;
	
	string s1 = s.substr(0,first+1);
	string s2 = s.substr(last);
	
	//cout << s1 << " " << s2 << endl;
	bool one = isPalindrome(s1, 0, s1.length()-1);
	bool sec = isPalindrome(s2,0,s2.length()-1);
	bool third = isPalindrome(s,0,n-1);
	
	if(one && sec && third) cout << "Yes" << endl;
	else cout << "No" << endl;
	
	
	return 0;
}
