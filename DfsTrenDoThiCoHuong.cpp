#include <bits/stdc++.h>
using namespace std;

int v, e, u;
vector<int> ke[1005];
bool visited[1005];

void dfs(int u){
	cout << u << " ";
	visited[u] = true;
	for(auto v : ke[u]){
		if(!visited[v]){
			dfs(v);
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
			ke[x].push_back(y);
		}
		dfs(u);
		cout << endl;
		for(int i = 0; i <= 1005; i++){
			ke[i].clear();
		}
	}
	return 0;
}

