#include <bits/stdc++.h>
using namespace std;

struct node{
	char data;
	node *left;
	node *right;
};

node* makeNode(char c){
	node *t = new node();
	t->data = c;
	t->left = t->right = NULL;
	return t;
}

void inorder(node *root){
	if(root != NULL){
		inorder(root->left);
		cout << root->data;
		inorder(root->right);
	}
}

bool isSign(char c){
	return (c == '+' || c == '-' || c == '*' || c == '/');
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while(t--){
		string s;
		cin >> s;
		stack<node*> st;
		for(int i = 0; i < s.size(); i++){
			if(isSign(s[i])){
				node *tmp = makeNode(s[i]);	
				tmp->right = st.top();
				st.pop();
				tmp->left = st.top();
				st.pop();
				st.push(tmp);
			}
			else{
				st.push(makeNode(s[i]));
			}
		}
		inorder(st.top());
		cout << endl;
	}	
	return 0;
}

