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

node *createBST(int a[], int s, int t){
	if(s > t) return NULL;
	int m = (s+t)/2;
	node *root = new node(a[m]);
	root->left = createBST(a, s, m-1);
	root->right = createBST(a, m+1, t);
	return root;
}

int countLeaf(node *root){
	if(root == NULL) return 0;
	if(root->left == NULL && root->right == NULL) return 1;
	else return countLeaf(root->left) + countLeaf(root->right);
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
		int a[n];
		for(int i = 0; i < n; i++){
			cin >> a[i];
		}
		sort(a, a+n);
		node *root = createBST(a, 0, n-1);
		cout << countLeaf(root) << endl;
	}
	return 0;
}

