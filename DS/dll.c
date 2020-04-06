#include<stdio.h>
#include<stdlib.h>

struct Node {
	int data;
	struct Node* left;
	struct Node* right;
};

struct Node* newNode(int data){
	struct Node *node = (struct Node*)malloc(sizeof(struct Node));
	node->data = data;
	node->left = NULL;
	node->right = NULL;
	return node;
}

struct Node* insert(struct Node *head,int data){
	if(head == NULL){
		head = newNode(data);
		return head;
	}
	struct Node* node = newNode(data);
	struct Node* temp = head;
	while(temp->right!=NULL){
		temp = temp->right;
	}
	temp->right = node;
	node->left = temp;
	return head;

}

void print(struct Node* head){
	while(head!=NULL){
		printf("%d ",head->data);
		head = head->right;
	}
}

int main(){
	struct Node* head = NULL;
	int n, data;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&data);
		head = insert(head, data);
	}
	print(head);
	return 0;
}