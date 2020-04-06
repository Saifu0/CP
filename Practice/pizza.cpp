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
	map<string,int> m;
	fo(i,n){
		string num;
		cin >> num;
		m[num]++;
	}
	double count = 1;
	int quarter = m["1/4"];
	int third = m["3/4"];

	while(quarter != 0 && third != 0){
		count += 1;
		quarter--;
		third--;
	}
	while(quarter != 0){
		count += 0.25;
		quarter--;
	}
	while(third!=0){
		count += 1;
		third--;
	}
	//cout << count << endl;
	int temp = ceil(count);
	double left = temp-count;

	//cout << left << endl;

	while(true){
		if(left >= 0.5 && m["1/2"] > 0){
			m["1/2"]--;
			left -= 0.5;
		}else{
			break;
		}
	}
	

	temp += ceil(m["1/2"]*0.5);

	cout << temp << endl;
	
	return 0;
}


