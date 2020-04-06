#include<bits/stdc++.h>
using namespace std;

class trieNode
{
public:
	trieNode** children;
	int weight;

	trieNode(){
		children = new trieNode*[26];
		for(int i=0;i<26;i++){
			children[i] = NULL;
		}
		weight = 0;
	}
	
};

void insert(string s, int weight, trieNode* root){
	if(s.empty()) return;

	trieNode* child;
	int index=s[0] - 'a';

	if(root->children[index]){
		child = root->children[index];
	}else{
		child = new trieNode();
		root->children[index] = child;
	}

	if(root->weight < weight){
		root->weight = weight;
	}

	insert(s.substr(1), weight, child);
}


int searchBest(string s, trieNode* root){
	int best = -1;
	trieNode* current = root;

	for(int i=0;i<s.length();i++){
		int index=s[i]-'a';

		trieNode* child = current->children[index];
		if(child){
			current = child;
			best = child->weight;
		}else{
			return -1;
		}
	}
	return best;
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