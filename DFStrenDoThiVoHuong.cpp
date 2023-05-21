#include <bits/stdc++.h>
using namespace std;

int v, e, u;
vector<int> ke[1005];
bool visited[1005];

void dfs(int i){
	cout << i << " ";
	visited[i] = true;
	for(auto x : ke[i]){
		if(!visited[x]){
			dfs(x);
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
		memset(visited,false,sizeof(visited));
		cin >> v >> e >> u;
		for(int i = 0; i < e; i++){
			int x, y;
			cin >> x >> y;
			ke[x].push_back(y);
			ke[y].push_back(x);
		}
		dfs(u);
		cout << endl;
		memset(ke,0,sizeof(ke));
	}
	return 0;
}

