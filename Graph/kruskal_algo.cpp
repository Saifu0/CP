#include<bits/stdc++.h>
using namespace std;

struct Graph {
	int src, dist, weight;
};

bool compare(Graph g1, Graph g2){
	return g1.weight < g2.weight;
}

int getparent(int src, int* parent){
	if(parent[src] == src){
		return src;
	}
	return getparent(parent[src],parent);
}

int main(){
	int v,e;
	cin >> v >> e;
	Graph g[e];

	for(int i=0;i<e;i++){
		cin >> g[i].src >> g[i].dist >> g[i].weight;
	}

	sort(g, g+e, compare);

	// for(int i=0;i<e;i++){
	// 	cout << g[i].src << g[i].dist << g[i].weight << endl;
	// }

	int parent[v];
	for(int i=0;i<v;i++){
		parent[i] = i;
	}
	int i=0;
	int j=0;

	Graph output[v-1];

	int count = 0;
	while(count != v-1){
		Edge current = g[i];
		int srcP = getparent(current.src, parent);
		int distP = getparent(current.dist, parent);

		if(srcP != dist){
			output[count] = g[i];
			count++;
			parent[srcP] = dist;
		}
		i++;
	}

	for(int i=0;i<v-1;i++){
		cout << output[i].src << " " << output[i].dist << " " << output[i].weight << endl;
	}
}