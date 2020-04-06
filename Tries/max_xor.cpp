#include<bits/stdc++.h>
using namespace std;

class Node {
public:
	Node* left;
	Node* right;
};

void insert(int n, Node* head){
	Node* current = head;
	for(int i=31;i>=0; i-- ){
		int b = (n>>i)&1; //Shifting n right by i bits and taking & of 1 to find 0/1 of ith bit

		if(b==0){
			if(!current->left){
				current->left = new Node();
			}
			current = current->left;
		}else{
			if(!current->right){
				current->right = new Node();
			}
			current = current->right;
		}
	}
}

int findMaxXor(Node* head, int* arr, int n){
	int max_xor = INT_MIN;
	for(int i=0;i<n;i++){
		int value = arr[i];
		Node* curr = head;
		int curr_xor = 0;
		for(int j=31;j>=0;j--){
			int b = (value>>j)&i;


			if(b==0){
				if(curr->right){
					curr_xor += pow(2,j);
					curr = curr->right;
				}else{
					curr = curr->left;
				}
			}else{
				if(curr->left){
					curr_xor += pow(2,j);
					curr = curr->left;
				}else{
					curr = curr->right;
				}
			}
		}
		max_xor = curr_xor >max_xor ? curr_xor : max_xor;
	}


	return max_xor;
}

int main(){
	int arr[6] = {8,1,2,15,10,5};
	Node* head = new Node();
	for(int i=0;i<6;i++){
		insert(arr[i],head);
	}
	cout << findMaxXor(head,arr,6);
	return 0; 
}