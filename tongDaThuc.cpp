#include <bits/stdc++.h>
using namespace std;

struct node{
	int heSo, soMu;
	node *next;
};

node* makeNode(int heSo, int soMu){
	node *newNode = new node();
	newNode->heSo = heSo;
	newNode->soMu = soMu;
	newNode->next = NULL;
	return newNode;
}

void pushBack(node **head, int heSo, int soMu){
	node *newNode = makeNode(heSo, soMu);
	node *s = *head;
	if(*head == NULL){
		*head = newNode;
		return;
	}
	while(s->next != NULL){
		s = s->next;
	}
	s->next = newNode;
}

void duyet(node *head){
	node *s = head;
	while(s!=NULL){
		cout << s->heSo	<< "*x^" << s->soMu;
		if(s->next!=NULL){
			cout << " + ";
		}
		s=s->next;
	}
}

void xuLi(string a, node **head){
	while(getline(cin,a)){
		int i = 0;
		while(i < a.size()){
			string soMu ="";
			string heSo = "";
			while(isalnum(a[i])){
				heSo += a[i];
				i++;
			}
			i+=3;
			while(isalnum(a[i])){
				soMu += a[i];
				i++;
			}
			i+=3;
			int hs = stoi(heSo);
			int sm = stoi(soMu);
			pushBack(head, hs, sm);
		}
		break;
	}
}

void solve(node *P, node *Q){
	node *R = NULL;
	node *t1 = P;
	node *t2 = Q;
	while(t1 != NULL && t2 != NULL){
		if(t1->soMu > t2->soMu){
			pushBack(&R, t1->heSo, t1->soMu);
			t1 = t1->next;
		}
		else if(t1->soMu < t2->soMu){
			pushBack(&R, t2->heSo, t2->soMu);
			t2 = t2->next;
		}
		else{
			node *tmp = new node();
			tmp->heSo = t1->heSo + t2->heSo;
			tmp->soMu = t1->soMu;
			pushBack(&R, tmp->heSo, tmp->soMu);
			free(tmp);
			t1=t1->next;
			t2=t2->next;
		}
	}
	while(t1 != NULL){
		pushBack(&R, t1->heSo, t1->soMu);
		t1 = t1->next;
	}
	while(t2 != NULL){
		pushBack(&R, t2->heSo, t2->soMu);
		t2 = t2->next;
	}
	duyet(R);
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	cin.ignore();
	while(t--){
		node *P = NULL;
		node *Q = NULL;
		string a, b;
		xuLi(a, &P);
		xuLi(b, &Q);
		solve(P, Q);
		cout << endl;	
	}
	return 0;
}

