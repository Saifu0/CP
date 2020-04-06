#include<bits/stdc++.h>
using namespace std;

class trieNode
{
public:
	trieNode** children;

	trieNode(){
		children = new trieNode*[26];
		for(int i=0;i<26;i++){
			children[i] = NULL;
		}
	}
	
};

void insert(string s, trieNode* root){
	if(s.empty()) return;

	trieNode* child;
	int index=s[0] - 'a';

	if(root->children[index]){
		child = root->children[index];
	}else{
		child = new trieNode();
		root->children[index] = child;
	}

	insert(s.substr(1),child);
}


int searchBest(string s, trieNode* root){
	trieNode* current = root;

	vector<char> ans;

	for(int i=0;i<s.length();i++){
		int index=s[i]-'a';

		trieNode* child = current->children[index];
		if(child){
			current = child;
			ans.push_back(s[i]);
		}else{
			
		}
	}
}

int main(){
	int n,q;
	cin >> n >> q;
	trieNode* root = new trieNode( );
	for(int i=0;i<n;i++){
		string s;
		cin >> s;
		int weight;
		scanf("%d",&weight);
		insert(s,weight,root);
	}
	while(q--){
		string str;
		cin >> str;
		cout << searchBest(str, root) << endl;
	}
}