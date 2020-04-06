#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
	int t;
	cin >> t;
	while(t--){
		ll n;
		cin >> n;
		vector<int> v;
		while(n>0){
			v.push_back(n%10);
			n /= 10;
		}
		reverse(v.begin(),v.end());
		int start,end;
		int x = v.size();
		
		start = x/2;
		end = start;

		if(x%2==0){
			start -= 1;
		}

		while(start >= 0 && end < x){
			if(v[start] < v[end]){
				v[start]+=1;
				break;
			}
			else if(v[start] > v[end]){
				break;
			}else{
				start--;
				end++;
			}
		}

		start = x/2;
		end = start;

		if(x%2==0){
			start -= 1;
		}

		while(start>=0){
			v[end] = v[start];
			start--;
			end++;
		}


		
		for(int i=0;i<v.size();i++){
			n = n*10 + v[i];
		}

		cout << n << endl;
	}
}