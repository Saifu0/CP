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
#define MAX 5000
int arr[MAX];

vi v;

void solve(){
  v.pb(30);
  v.pb(42);

  for(int i=0;i<MAX;i++){
    arr[i] = 1;
  }

  for(int i=2;i<sqrt(MAX);i++){
    for(int j=i+i;j<MAX;j+=i){
      arr[j] = 0;
    }
  }

  for(int i=43;i<MAX;i++){
    int count = 0,j=2;
    while(j<(i+1)/2){
      if(arr[j]== 1 && i%j==0){
        count++;
      }
      if(count>=3){
        v.pb(i);
        break;
      }
      j++;
    }
  }


}


int main(){
  int t;
  cin >> t;
  solve();
  while(t--){
    int n;
    cin >> n;

    cout << v[n-1] << endl;

  }


  return 0;
}
