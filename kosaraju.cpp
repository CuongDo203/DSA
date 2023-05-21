#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> adj[1001];
vector<int> t_adj[1001];
stack<int> st;
bool visited[1001];

void input(){
	cin >> n >> m;
	for(int i = 0; i < m; i++){
		int x, y;
		cin >> x >> y;
		adj[x].push_back(y);
		t_adj[y].push_back(x);
	}
}

void dfs_1(int u){
	visited[u] = true;
	for(auto v : adj[u]){
		if(!visited[v]){
			dfs_1(v);
		}
	}
	st.push(u);
}

void dfs_2(int u){
	visited[u] = true;
	cout << u << " ";
	for(auto v : t_adj[u]){
		if(!visited[v]){
			dfs_2(v);
		}
	}
}

void kosaraju(){
	for(int i = 1; i <= n; i++){
		if(!visited[i]){
			dfs_1(i);
		}
	}
	memset(visited, false, sizeof(visited));
	int scc = 0;
	while(!st.empty()){
		int v = st.top();
		st.pop();
		if(!visited[v]){
			dfs_2(v);
			scc++;
			cout << endl;
		}
	}
	cout << scc << endl;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	input();
	kosaraju();
	return 0;
}

