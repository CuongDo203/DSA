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

int cnt = 0;

void count(node *root){
	if(root == NULL) return;
	if(root->right != NULL){
		if(root->right->left == NULL && root->right->right == NULL){
			cnt += root->right->data;
			//return;
		}
	}
	count(root->left);
	count(root->right);
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
		map<int, node*> mp;
		for(int i = 0; i < n; i++){
			int u, v;
			char c;
			cin >> u >> v >> c;
			if(mp.find(u) == mp.end()){  //neu chua co
				root = new node(u);
				if(c=='L'){
					root->left = new node(v);
					mp[v] = root->left;    //cha cua v la root->left
				}
				else{
					root->right = new node(v);
					mp[v] = root->right;
				}
				mp[u] = root;
			}
			else{
				if(c == 'L'){
					mp[u]->left = new node(v);
					mp[v] = mp[u]->left;
				}
				else{
					mp[u]->right = new node(v);
					mp[v] = mp[u]->right;
				}
			}
		}
		count(root);
		cout << cnt << endl;
		cnt = 0;
	}
	return 0;
}

