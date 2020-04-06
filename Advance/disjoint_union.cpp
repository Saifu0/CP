#include<bits/stdc++.h>
using namespace std;

struct Node {
	int data,rank;		
	struct Node parent;
};

map<int,Node> mp;


void makeset(int data){
	Node node = new Node();
	node.data = data;
	node.rank = 0;
	node.parent = node;
	mp.make_pair(data,node);
}

void Union(int a,int b){
	Node node1 = mp[a];
	Node node2 = mp[b];

	Node parent1 = findpar(node1);
	Node parent2 = findpar(node2);

	if(parent1.data == parent2.data) return;

	if(parent1.rank >= parent2.rank){
		parent1.rank = (parent1.rank == parent2.rank) ? parent1.rank + 1 : parent1.rank;
		parent2.parent =parent1;
	}else{
		parent1.parent = parent2;
	}
}

int findpar(int data){ return findpar(mp[data]).data; }

Node findpar(Node node){
	Node parent  = node.parent;
	if(parent == node){
		return parent;
	}
	node.parent = findpar(node.parent);
	return node.parent;
}

int main(){
	makeset(1);
	makeset(2);
	makeset(3);
	makeset(4);
	makeset(5);
	makeset(6);
	makeset(7):

	Unions(1,4);
	Unions(2,3);
	Unions(4,5);
	Unions(6,7);
	Unions(4,7);
	Unions(1,3);

	cout << findpar(5) << endl;
	cout << findpar(2) << endl;	

}
