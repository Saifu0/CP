#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

vector<ll> solve(vector<ll> arr, ll MAX){
	vector<ll> solutionIndex;
	vector<ll> solutionValue;
	vector<ll> currIndex;
	vector<ll> currValue;

	int n = arr.size();

	ll maxScore = 0;

	ll start = n;

	ll sum = 0;

	while((currIndex.size() >0 && currIndex[0] !=0 ) || currIndex.size() == 0){
		start =start- 1;

			for(int i=start;i>=0;i--){
				ll curr = arr[i];

				ll temp = sum + curr;

				if(temp == MAX){
					sum = temp;
					currIndex.push_back(i);
					currValue.push_back(curr);
					break;
				}
				else if(temp > MAX){
					continue;
				}

				else if(temp < MAX){
					sum = temp;
					currIndex.push_back(i);
					currValue.push_back(curr);
					continue;
				}
			}

			if(maxScore < sum){
				maxScore = sum;

				solutionValue.clear();
				solutionIndex.clear();

				for(int i=0;i<currIndex.size();i++){
					solutionIndex.push_back(currIndex[i]);
				}

				for(int i=0;i<currValue.size();i++){
					solutionValue.push_back(currValue[i]);
				}
			}

			if(maxScore == MAX)
				break;

			if(currValue.size() != 0){
				ll lastVal = currValue[currValue.size()-1];
				currValue.pop_back();
				sum = sum-lastVal;
			}

			if(currIndex.size() != 0){
				ll lastIndex = currIndex[currIndex.size()-1];
				currIndex.pop_back();
				start = lastIndex;
			}

			if(currIndex.size() == 0 && start == 0){
				break;
			}
		
	}

	return solutionIndex;

}

int main(){
	string s[] = {"a_example","b_small","c_medium","d_quite_big","e_also_big"};
	

	for(int i=0;i<5;i++){
		string filename = s[i];
		string input_path = filename + ".in";
		string output_path =  filename + ".out";

		auto hi = freopen(input_path.c_str(),"r", stdin);
		ll n,m;
		cin >> n >> m;
		vector<ll> arr;
		for(int i=0;i<m;i++){
			ll data;
			cin >> data;
			arr.push_back(data);
		}

		auto out = fopen(output_path.c_str(), "w");
		vector<ll> ans = solve(arr, n);

		// cout << ans.size() << endl;
		// for(int i=ans.size()-1;i>=0;i--){
		// 	cout << ans[i] << " ";
		// }
		// cout << "\n";

		fprintf(out, "%lld\n", ans.size());
		for(int i=ans.size()-1;i>=0;i--){
			fprintf(out, "%lld ", ans[i]);
		}
		fprintf(out,"\n");
		fclose(out);
		cout << filename << endl;

	}
	

	
}