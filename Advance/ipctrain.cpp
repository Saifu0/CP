#include<bits/stdc++.h>
using namespace std;

class process {
	public:
		int day,lec,s;	
};

class compare {
	public:
		bool operator()(process const&p1, process const&p2){
			return p1.s < p2.s; 
		}
};

bool comp(process a, process b){
	return a.day < b.day;
}

int main(){
	int t;
	cin >> t;
	while(t--){
		int n,d;
		cin >> n >> d;
		priority_queue<process, vector<process>, compare> q;
		
		process p[n];
		for(int i=0;i<n;i++){
			int x,y,z;
			cin >> x >> y >> z;
			p[i].day = x;
			p[i].lec = y;
			p[i].s = z;
		}

		sort(p,p+n,comp);
     		int ans = 0;
		q.push(p[0]);
		int curr = 0;
		while(true){
			for(int i=1;i<n;i++){
                                if(curr==p[i].day) q.push(p[i]);
                        }
			if(!q.empty()){
				process temp = q.top();
                        	q.pop();
                	        if(temp.lec != 1){
                                	--temp.lec;
                               		q.push(temp);
                        	}
			}
			if(curr==d){
				while(!q.empty()){
					process dem = q.top();
                                	ans += (dem.lec*dem.s );
                                	q.pop();
				}
				break;	
			}
			curr++;
		}
		cout << ans << endl;
	}
}
