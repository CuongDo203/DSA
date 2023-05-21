#include <bits/stdc++.h>
using namespace std;

struct node{
	int data;
	node *left;
	node *right;
	node(int x){
		data = x;
		left = right = NULL;
	}
};

void makeRoot(node *root, int u, int v, char c){
	if(c=='L') root->left = new node(v);
	else root->right = new node(v);
}

void insertNode(node *root, int u, int v, char c){
	if(root == NULL) return;
	if(root->data == u){
		makeRoot(root, u, v, c);
		return;
	}
	insertNode(root->left, u, v, c);
	insertNode(root->right, u, v, c);
}

bool isFullTree(node *root){
	if(root == NULL) return true;
	if(root->left == NULL && root->right == NULL){
		return true;
	}
	node *r, *l;
	r = root->right;
	l = root->left;
	if(r&&l){
		if(isFullTree(l)&&isFullTree(r)) return true;
	}
	return false;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		node *root = NULL;
		for(int i = 0; i < n; i++){
			int u, v;
			char c;
			cin >> u >> v >> c;
			if(root == NULL){
				root = new node(u);
				makeRoot(root, u, v, c);
			}
			else{
				insertNode(root,u,v,c);
			}
		}
		if(isFullTree(root)){
			cout << "1\n";
		}
		else{
			cout << "0\n";
		}
	}
	return 0;
}

