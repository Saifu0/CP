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
#define F first
#define S second
#define sz(v) (int)v.size()
#define mod 1000000007

void c_p_c()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}

int main(){
	c_p_c();

	int a[6];
	mp m;
	fo(i,6) cin >> a[i], m[a[i]] += 1;
	

	if(m.size()==3){
		bool con1 = false;
		for(auto it=m.begin();it!=m.end();it++){
			if(it->S == 4){ con1 =true; }
		}

		if(con1 == true)
			cout << "Bear\n";
		else 
			cout << "Alien\n";
		return 0;
	}

	if(m.size()==1){
		cout << "Elephant\n";
		return 0;
	}

	if(m.size()==2){
		bool con1 = false,con2 = false;
		for(auto it=m.begin();it!=m.end();it++){
			if(it->S == 4){ con1 =true; }
			if(it->S ==5) { con2 = true;}
		}
		if(con2==true){
			cout << "Bear\n";
			return 0;
		}
		if(con1==true)
			cout << "Elephant\n";
		else
			cout << "Alien\n";
		return 0;
	}

	else{
		cout << "Alien\n";
		return 0;
	}

	return 0;
}