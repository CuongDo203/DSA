#include <bits/stdc++.h>
using namespace std;

int n, m, s, t;
vector<int> ke[1005];
bool visited[1005];
int p[1005];

void input(){
	memset(visited, false, sizeof(visited));
	memset(ke, 0, sizeof(ke));
	memset(p,0,sizeof(p));
	cin >> n >> m >> s >> t;
	for(int i = 0; i < m; i++){
		int x, y;
		cin >> x >> y;
		ke[x].push_back(y);
		ke[y].push_back(x);
	}
}

void dfs(int u){
	visited[u] = true;
	for(auto v : ke[u]){
		if(!visited[v]){
			p[v] = u;
			dfs(v);
		}
	}
}

void solve(){
	dfs(s);
	if(!visited[t]){
		cout << "-1\n";
	}
	else{
		vector<int> path;
		while(t!=s){
			path.push_back(t);
			t = p[t];
		}
		path.push_back(s);
		reverse(path.begin(), path.end());
		for(auto x : path){
			cout << x << " ";
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
		input();
		solve();
	}
	return 0;
}

