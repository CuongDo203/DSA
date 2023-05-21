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

node *insertNode(node *root, int x){
	if(root == NULL) return new node(x);
	if(root->data < x){
		root->right = insertNode(root->right, x);
	}
	else{
		root->left = insertNode(root->left, x);
	}
	return root;
}

void postOrder(node *root){
	if(root != NULL){
		postOrder(root->left);
		postOrder(root->right);
		cout << root->data << " ";
	}
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
			int x;
			cin >> x;
			if(root == NULL){
				root=new node(x);
			}
			else{
				insertNode(root, x);
			}
		}
		postOrder(root);
		cout << endl;
	}	
	return 0;
}

