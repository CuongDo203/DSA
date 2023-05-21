#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> ke[1005];
bool visited[1005];
vector<pair<int,int>> edge;

void input(){
	memset(visited, false, sizeof(visited));
	memset(ke,0,sizeof(ke));
	edge.clear();
	cin >> n >> m;
	for(int i = 0; i < m; i++){
		int x, y;
		cin >> x >> y;
		edge.push_back({x,y});
		ke[x].push_back(y);
		ke[y].push_back(x);
	}
}

void dfs(int u, int x, int y){
	visited[u] = true;
	for(auto v : ke[u]){
		if(x == u && y == v || x == v && y == u){
			continue;
		}
		if(!visited[v]){
			dfs(v,x,y);
		}
	}
}

void solve(){
	//dem so thanh phan lien thong
	int cnt = 0;
	for(int i = 1; i <= n; i++){
		if(!visited[i]){
			cnt++;
			dfs(i,-1,-1);
		}
	}
	//duyet ds canh
	for(auto e : edge){
		int x=e.first, y = e.second;
		int dem = 0;
		memset(visited, false, sizeof(visited));
		for(int i = 1; i <= n; i++){
			if(!visited[i]){
				dem++;
				dfs(i,x,y);
			}
		}
		if(dem > cnt){
			cout << x << " " << y << " ";
		}
	}
	cout << endl;
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

