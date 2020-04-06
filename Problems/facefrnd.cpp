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




// int main(){
// 	int n;
// 	cin >> n;
// 	set<int> frnd;
// 	set<int> fof;
// 	while(n--){
// 		int id,m;
// 		cin >> id >> m ;
// 		frnd.insert(id);
// 		if(fof.end()!=fof.find(id)) fof.erase(id);
// 		for(int i =0;i<m;i++){
// 			cin >> id;
// 			if(frnd.end() == frnd.find(id)) fof.insert(id);
// 		}
// 	}
// 	cout << fof.size() << endl;
// 	return 0;
// }


 int main(){
 	int n;
 	cin >> n;
 	set<int> s;
 	vi v;

 	while(n--){
 		int id,m;
 		cin >> id >> m;
 		v.pb(id);
 		for(int i=0;i<m;i++){
 			cin >> id;
 			s.insert(id);
 		}
 		
 	}
 	for(int i=0;i<v.size();i++)
 		s.erase(v[i]);


 	cout << s.size() << endl;
 }