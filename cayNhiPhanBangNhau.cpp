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

bool check(node *r1, node *r2){
	if(r1 == NULL && r2 == NULL) return true;
	if(r1 != NULL && r2 != NULL){
		return (r1->data == r2->data && check(r1->left, r2->left) && check(r1->right, r2->right));
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
		int n1, n2;
		node *r1 = NULL;
		node *r2 = NULL;
		cin >> n1;
		for(int i = 0; i < n1; i++){
			int u, v;
			char c;
			cin >> u >> v >> c;
			if(r1 == NULL){
				r1 = new node(u);
				makeRoot(r1, u, v, c);
			}
			else{
				insertNode(r1, u, v, c);
			}
		}
		cin >> n2;
		for(int i = 0; i < n2; i++){
			int u, v;
			char c;
			cin >> u >> v >> c;
			if(r2 == NULL){
				r2 = new node(u);
				makeRoot(r2, u, v, c);
			}
			else{
				insertNode(r2, u, v, c);
			}
		}
		if(check(r1,r2)) cout << "1\n";
		else cout << "0\n";
	}
	return 0;
}

