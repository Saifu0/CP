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
	int t;
	cin >> t;
	while(t--){
		double a,b,c,d;
		cin >> a >> b >> c >> d;

		double s = (a+b+c+d)*0.5;

		double ans = sqrt((s-a)*(s-b)*(s-c)*(s-d));

		printf("%.2f\n",ans);
	}
	

	
	return 0;
}


