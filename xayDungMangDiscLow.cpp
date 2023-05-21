#include <bits/stdc++.h>
using namespace std;

int n, m;
int timer=0;
vector<int> ke[1001];
int disc[1001], low[1001];
bool vs[1001], in_stack[1001];
stack<int> st;
int scc = 0;

void input(){
	cin >> n >> m;
	for(int i = 0; i < m; i++){
		int x, y;
		cin >> x >> y;
		ke[x].push_back(y);
	}
	memset(vs, false, sizeof(vs));
	memset(in_stack, false, sizeof(in_stack))
}

void dfs(int u){
	vs[u] = true;
	low[u] = disc[u] = ++timer;
	st.push(u);
	in_stack(u) = true;
	for(auto v : ke[u]){
		if(!vs[v]){
			dfs(v);
			low[u] = min(low[u], low[v]);
		}
		else{
			low[u] = min(low[u], disc[v]);
		}
	}
	if(disc[u] == low[u]){
		scc++;
		while(st.top() != u){
			cout << st.top() << " ";
			in_stack[st.top()] = false;
			st.pop();
		}
		cout << st.top() << endl;
		in_stack[st.top()] = false;
		st.pop();
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	input();
	for(int i = 1; i <= n; i++){
		if(!vs[i]){
			dfs(i);
		}
	}
	cout << scc << endl;
	return 0;
}

