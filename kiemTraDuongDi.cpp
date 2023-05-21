#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> ke[1005];
bool visited[1005];

void dfs(int u){
	visited[u] = true;
	for(auto v : ke[u]){
		if(!visited[v]){
			dfs(v);
		}
	}
}

void solve(){
	memset(visited, false, sizeof(visited));
	for(int i = 0; i <= 1005; i++){
		ke[i].clear();
	}
	cin >> n >> m;
	for(int i = 0; i < m; i++){
		int x, y;
		cin >> x >> y;
		ke[x].push_back(y);
		ke[y].push_back(x);
	}
	int q;
	cin >> q;
	while(q--){
		memset(visited, false, sizeof(visited));
		int x, y;
		cin >> x >> y;
		dfs(x);
		if(!visited[y]){
			cout << "NO";
		}
		else{
			cout << "YES";
		}
		cout << endl; 
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while(t--){
		solve();
	}
	return 0;
}

