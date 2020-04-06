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
	int n;
	cin >> n;
	string s;
	cin >> s;

	int mn = INT_MAX;

	string ans = "ACTG";
	

	for(int i=0;i<n-3;i++){
		
		int start = i;
		int temp=0;
		int j=0;
		while(j<4){
			int temp1 = 0;
			int temp2=0;
			int f=s[start],e=ans[j];
			//cout << f << " " << e << endl;
			while(f != e){
				if(f==90){
					f = 65;
					temp1++;
					continue;
				}
				 f= f + 1;

				 temp1++;
			}
			f=s[start],e=ans[j];
			while(f!=e){
				if(f==65){
					f = 90;
					temp2++;
					continue;
				}
				f = f - 1;

				temp2++;
			}

			//cout << temp1 << " " << temp2 << endl; 
			j++;
			start++;
			temp += min(temp1,temp2);
		}

		if(mn > temp)
			mn = temp;
	}

	cout << mn << endl;
	
	return 0;
}


