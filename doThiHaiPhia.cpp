#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> ke[1001];
int color[1001]; 

void input(){
	memset(ke,0,sizeof(ke));
	cin >> n >> m;
	for(int i = 0; i < m; i++){
		int x,y;
		cin >> x >> y;
		ke[x].push_back(y);
		ke[y].push_back(x);
	}
	memset(color,-1,sizeof(color));
}

bool bfs(int u){
	queue<int> q;
	q.push(u);
	color[u] = 0;
	while(!q.empty()){
		int v = q.front();
		q.pop();
		for(int x : ke[v]){
			if(color[x] == -1){
				color[x] = 1-color[v];
				q.push(x);
			}
			else if(color[x] == color[v]){
				return false;
			}
		}
	}
	return true;
}

bool dfs(int u, int par){
	color[u] = 1 - color[par];
	for(int v : ke[u]){
		if(color[v] == -1){
			if(!dfs(v,u)) return false;
		}
		else if(color[v] == color[u]) return false;
	}
	return true;
} 

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while(t--){
		input();
		bool check = true;
		for(int i = 1; i <= n; i++){
			if(color[i] == -1){
				if(!bfs(i)){
					check = false;
					break;
				}
			}
		}
		if(check) cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}

