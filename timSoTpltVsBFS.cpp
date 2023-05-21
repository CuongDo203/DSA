#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> ke[1005];
bool visited[1005];

void input(){
	memset(visited, false, sizeof(visited));
	memset(ke, 0, sizeof(ke));
	cin >> n >> m;
	for(int i = 0; i < m; i++){
		int x, y;
		cin >> x >> y;
		ke[x].push_back(y);
		ke[y].push_back(x);
	}
}

void bfs(int u){
	queue<int> q;
	q.push(u);
	visited[u] = true;
	while(!q.empty()){
		int v = q.front();
		q.pop();
		for(auto it : ke[v]){
			if(!visited[it]){
				q.push(it);
				visited[it] = true;
			}
		}
	}
}

void solve(){
	int cnt = 0;
	for(int i = 1; i <= n; i++){
		if(!visited[i]){
			bfs(i);
			cnt++;
		}
	}
	cout << cnt << endl;
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

