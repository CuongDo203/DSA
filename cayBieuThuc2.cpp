#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct node{
	string data;
	node *left;
	node *right;
};

node *makeNode(string x){
	node *tmp = new node();
	tmp->data = x;
	tmp->left = tmp->right = NULL;
	return tmp;
}

bool isOp(string c){
	return (c == "+" || c == "-" || c == "*" || c == "/");
}

ll tinh(ll a, ll b, string c){
	if(c == "+") return a+b;
	if(c == "-") return a-b;
	if(c == "*") return a*b;
	return a/b;
}

vector<string> v, v2;

void NLR(node *root){
	if(root!=NULL){
		v2.push_back(root->data);
		NLR(root->left);
		NLR(root->right);
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while(t--){
		v.clear();
		v2.clear();
		int n;
		cin >> n;
		for(int i = 0; i < n; i++){
			string s;
			cin >> s;
			v.push_back(s);
		}
		queue<node*> q;
		for(int i = v.size()-1; i >= 0; i--){
			if(!isOp(v[i])){
				q.push(makeNode(v[i]));
			}
			else{
				node *tmp = new node();
				tmp->data = v[i];
				tmp->right = q.front();
				q.pop();
				tmp->left = q.front();
				q.pop();
				q.push(tmp);
			}
		}
		NLR(q.front());
		while(!q.empty()){
			q.pop();
		}
		stack<ll> st;
		for(int i = v2.size()-1; i >= 0; i--){
			if(!isOp(v2[i])){
				st.push(stoll(v2[i]));
			}
			else{
				ll t1 = st.top();
				st.pop();
				ll t2 = st.top();
				st.pop();
				ll res = tinh(t1, t2, v2[i]);
				st.push(res);
			}
		}
		cout << st.top() << endl;
		st.pop();
	}	
	return 0;
}

