#include<stdio.h>
#include<stdlib.h>

struct Node {
	int data;
	struct Node* left;
	struct Node* right;
};

struct Node* insert(struct Node* head, int data){
	if(head == NULL){
		struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
		newNode->data = data;
		newNode->left = NULL;
		newNode->right = NULL;
		return newNode;
	}
	if(data > head->data){
		head->right = insert(head->right, data);
	}else{
		head->left = insert(head->left, data);
	}
	return head;
}

struct Node* minValueNode(struct Node* head){
	struct Node* curr = head;
	if(curr && curr->left != NULL){
		curr = curr->left;
	}
	return curr;
}

struct Node* delete(struct Node* head, int value){
	if(head == NULL) return head;

	if(value > head->data){
		head->right = delete(head->right, value);
	}else if(value < head->data){
		head->left = delete(head->left, value);
	}else{
		if(head->left == NULL){
			struct Node* temp = head->right;
			free(head);
			return temp;
		}else if(head->right == NULL){
			struct Node* temp = head->left;
			free(head);
			return temp;
		}
		struct Node* temp = minValueNode(head->right);
		head->data = temp->data;
		head->right = delete(head->right, temp->data);
	}
	return head;
}

void inorder(struct Node* head){
	if(head != NULL){
		inorder(head->left);
		printf("%d\n", head->data);
		inorder(head->right);	
	}
	
}

int main(){
	struct Node* head = NULL;
	int data;
	for(int i=0;i<7;i++){
		scanf("%d",&data);
		head = insert(head, data);
	}
	head = delete(head,3);
	inorder(head);
}