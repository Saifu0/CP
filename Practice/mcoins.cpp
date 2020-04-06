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

int a[1000009];


int main(){
  int l,r,n;
  cin >> l >> r >> n;
  int max = INT_MIN;
  int b[n];
  for(int i=0;i<n;i++){
    int data;
    cin >> data;
    if(data > max)
      max = data;
    b[i] = data;
  }

  a[1] = 1;
  for(int i=2;i<=max;i++){
    if(!a[i-1])
      a[i] = 1;
    if(i-l>=0 && !a[i-l])
      a[i] = 1;
    if(i-r>=0 && !a[i-r])
      a[i] = 1;
  }

  for(int i=0;i<n;i++){
    if(a[b[i]]) cout << "A";
    else cout << "B";
  }
  cout << endl;

  return 0;
}
