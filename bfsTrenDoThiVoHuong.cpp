#include <bits/stdc++.h>
using namespace std;

int v, e, u;
vector<int> adj[1005];
bool visited[1005];

void bfs(int u){
	queue<int> q;
	q.push(u);
	visited[u] = true;
	while(!q.empty()){
		int v = q.front();
		cout << v << " ";
		q.pop();
		for(auto x : adj[v]){
			if(!visited[x]){
				q.push(x);
				visited[x] = true;
			}
		}
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while(t--){
		memset(visited, false, sizeof(visited));
		cin >> v >> e >> u;
		for(int i = 0; i < e; i++){
			int x, y;
			cin >> x >> y;
			adj[x].push_back(y);
			adj[y].push_back(x);
		}
		bfs(u);
		cout << endl;
		memset(adj,0,sizeof(adj));
	}
	return 0;
}

