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
				p[it] = v;
				q.push(it);
				visited[it] = true;
			}
		}
	}
}

void solve(){
	bfs(s);
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

