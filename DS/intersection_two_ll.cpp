#include<bits/stdc++.h>
using namespace std;

struct Node {
	int data;
	Node* left;
};

Node* Insert(Node* head, int data){
	Node* newNode = new Node();
	newNode->left = NULL;
	newNode->data = data;

	if(head == NULL){
		head = newNode;
		return head;
	}

	newNode->left = head;
	head = newNode;

	return head;
}

Node* rotate(Node* head, int k){
	Node* temp = head;
	for(int i=0;i<k;i++){
		temp = temp->left;
	}

	Node* temp1 = head;
	while(temp1->left != NULL){
		temp1 = temp1->left;
	}
	temp1->left = head;
	head = temp->left;
	temp->left = NULL;

	return head;

}

void print(Node* head){
	cout << "Printing list elements\n";
	while(head != NULL){
		cout << head->data << " ";
		head = head->left;
	}
}

int main(){
	Node* head = NULL;
	int n;
	cin >> n;
	for(int i=0;i<n;i++){
		int num;
		cin >> num;
		head = Insert(head, num);
	}

	print(head);

	head = rotate(head, 4);

	print(head);
	return 0;
}