#include <bits/stdc++.h>
using namespace std;

vector<int> ke[100];
bool vs[100][100];
int n, m, ans = 0;

void dfs(int u, int longest){
	ans = max(ans, longest);
	//vs[u] = true;
	for(auto v : ke[u]){
		if(!vs[u][v]){
			vs[u][v] = vs[v][u] = true;
			dfs(v, longest+1);
			vs[u][v] = vs[v][u] = false;
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
		memset(vs, false,sizeof(vs));
		memset(ke, 0, sizeof(ke));
		ans = 0;
		cin >> n >> m;
		for(int i = 0; i < m; i++){
			int x, y;
			cin >> x >> y;
			ke[x].push_back(y);
			ke[y].push_back(x);
		}
		for(int i = 0; i < n; i++){
			dfs(i, 0);
		}
		cout << ans << endl;
	}
	return 0;
}

