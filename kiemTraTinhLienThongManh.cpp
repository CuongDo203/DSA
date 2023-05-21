#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> ke[1005];
bool visited[1005];

void input(){
	memset(ke,0,sizeof(ke));
	memset(visited, false, sizeof(visited));
	cin >> n >> m;
	for(int i = 0; i < m; i++){
		int x, y;
		cin >> x >> y;
		ke[x].push_back(y);
	}
}

void dfs(int u){
	visited[u] = true;
	for(auto v : ke[u]){
		if(!visited[v]){
			dfs(v);
		}
	}
}

void solve(){
	for(int i = 1; i <= n; i++){
		memset(visited, false, sizeof(visited));
		dfs(i);
		for(int j = 1; j <= n; j++){
			if(!visited[j]){
				cout << "NO\n";
				return;
			}
		}
	}
	cout << "YES\n";
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while(t--){
		input();
		solve();
	}
	return 0;
}

