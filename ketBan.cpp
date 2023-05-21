#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> ke[100005];
bool visited[100005];
int ans = 1, cnt = 1;

void input(){
	memset(ke,0,sizeof(ke));
	memset(visited, false, sizeof(visited));
	cin >> n >> m;
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
			cnt++;
			dfs(v);
		}
	}
	ans = max(ans, cnt);
}

void solve(){
	for(int i = 1; i <= n; i++){
		if(!visited[i]){
			dfs(i);
		}
		cnt=1;
	}
	cout << ans << endl;
	ans = 1;
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

