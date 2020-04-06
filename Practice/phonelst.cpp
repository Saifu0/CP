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
#define APLHA 10

struct tnode {
	int prefix;
	tnode* child[APLHA];
};

struct trie {
	tnode* root;
};

tnode* createnode(){
	tnode*t = new tnode();
	if(t){
		t->prefix = 0;
		fo(i,APLHA)
			t->child[i] = NULL;
	}
	return t;
}

void initialize(trie*t){
	t->root = createnode();
}

void insert(trie*t, string s){
	tnode *temp = t->root;
	int n = s.length();
	//t->count++;
	for(int i=0;i<n;i++){
		int ind = (int)(s[i]-'0');
		if(!temp->child[ind]){
			temp->child[ind] = createnode();
		}
		temp = temp->child[ind];
		(temp->prefix)++;
	}
	//temp->word = t->count;
}

int prefix_count(trie*t, string s){
	tnode* temp = t->root;
	int n = s.length();

	for(int i=0;i<n;i++){
		int ind = (int)(s[i]-'0');
		if(!temp->child[ind]) return 0;
		temp = temp->child[ind];
	}
	return temp->prefix;
}

int main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		string *arr = new string[n];
		fo(i,n) cin >> arr[i];

		trie t;
		initialize(&t);

		int flag=0;
		sort(arr,arr+n);

		for(int i=n-1;i>=0;i--){
			insert(&t,arr[i]);
			if(prefix_count(&t,arr[i]) > 1){
				flag=1;
				break;
			}
		}
		if(flag) cout << "NO" << endl;
		else cout << "YES" << endl;
	}
	
	return 0;
}


