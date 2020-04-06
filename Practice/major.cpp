#include<bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define fo(i,n) for(int i=0;i<n;i++)
#define Fo(i,k,n) for(int i=k;i<n;i++)
#define rep(n) for(int i=n-1;i>=0;i--)
#define ii pair<int,int>
#define m map<int,int>
#define pb push_back
#define ll long long

int main(){
  int t;
  cin >> t;
  while(t--){
    m mp;
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
      int data;
      cin >> data;
      mp[data]++;
    }
    int flag = 0;
    int data;
    for(auto it=mp.begin();it!=mp.end();it++){
      if(it->second > n/2){
        flag = 1;
        data  = it->first;
        break;
      }
    }

    if(flag)
    cout << "YES " << data << endl;
    else
    cout << "NO" << endl;
  }

  return 0;
}
