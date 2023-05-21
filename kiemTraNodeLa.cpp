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
	if(c == 'L') root->left = new node(v);
	else root->right = new node(v);
}

void insertNode(node *root, int u, int v, char c){
	if(root == NULL){
		return;
	}
	if(root->data == u){
		makeRoot(root, u, v, c);
	}
	else{
		insertNode(root->left, u, v, c);
		insertNode(root->right, u, v, c);
	}
}

bool check(node *root, int h, int &maxh){
	if(root == NULL) return true;
	if(root->left == NULL && root->right == NULL){
		if(maxh == 0){
			maxh = h;
			return true;
		}
		else{
			return h == maxh;
		}
	}
	else 
		return check(root->left, h+1, maxh) && check(root->right, h+1, maxh);
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while(t--){
		node *root = NULL;
		int n;
		cin >> n;
		for(int i = 0; i < n; i++){
			int u, v;
			char c;
			cin >> u >> v >> c;
			if(root == NULL){
				root = new node(u);
				makeRoot(root, u, v, c);
			}
			else{
				insertNode(root, u, v, c);
			}
		}
		int maxh = 0;
		if(check(root, 0, maxh)){
			cout << "1\n";
		}
		else{
			cout << "0\n";
		}
	}	
	return 0;
}

