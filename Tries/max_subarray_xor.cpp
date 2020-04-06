#include<bits/stdc++.h>
using namespace std;

struct Node {
	int value;
	Node *arr[2];
};

Node* newNode(){
	Node* temp = new Node;
	temp->value = 0;
	temp->arr[0] = temp->arr[1] = NULL;
	return temp;
}

void insert(Node* head, int n){
	Node* temp =  head;
	for(int i=31;i>=0;i--){
		int b =(n>>i) & 1;

		if(temp->arr[b] == NULL)
			temp->arr[b] = newNode();

		temp = temp->arr[b];
	}
	temp->value = n;
}

int query(Node* root, int n){
	Node* temp =  root;
	for(int i=31;i>=0;i--){
		int b = (n>>i) & 1;

		if(temp->arr[1-b] != NULL)
			temp = temp->arr[1-b];

		else if(temp->arr[b] != NULL)
			temp = temp->arr[b];
	}
	return n^(temp->value);
}

int maxSubarrayXor(int*arr, int n){
	Node* root = newNode();

	insert(root,0);

	int res = INT_MIN, pre_xor = 0;

	for(int i=0;i<n;i++){
		pre_xor = pre_xor^arr[i];
		insert(root, pre_xor);

		res = max(res, query(root, pre_xor));
	}
	return res;
}

int main(){
	int n;
	cin >> n;
	int arr[n];
	for(int i=0;i<n;i++){
		cin >> arr[i];
	}
	cout << maxSubarrayXor(arr,n) << endl;
}