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
	if(root==NULL) return;
	if(root->data == u){
		makeRoot(root, u, v, c);
		return;
	}
	insertNode(root->left, u, v, c);
	insertNode(root->right, u, v, c);	
}

bool isPerfectTree(node *root, int level){
	queue<node*> q;
	q.push(root);
	int s= 0, f=0, l=0;
	while(!q.empty()){
		s=q.size();
		f=0;
		if(s != int(pow(2,l))) return false;
		for(int i = 0; i < s; i++){
			node *t = q.front();
			q.pop();
			if(t->left != NULL) q.push(t->left);
			if(t->right != NULL) q.push(t->right);
		}
		l++; 
	}
	return true; 
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
				insertNode(root, u, v, c);
			}
		}
		if(isPerfectTree(root, 0)){
			cout << "Yes\n";
		} 
		else{
			cout << "No\n";
		}
	}
	return 0;
}

