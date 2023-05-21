#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;

int n, k, m;
vector<pii> sheep;
bool vs[101][101];

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

set<pair<pii,pii>> fence;

void input(){
	cin >> n >> k >> m;
	for(int i = 0; i < m; i++){
		int u, v, x, y;
		cin >> u >> v >> x >> y;
		fence.insert({{u,v}, {x,y}});
		fence.insert({{x,y}, {u,v}});
	}
	for(int i = 0; i < k; i++){
		int x, y;
		cin >> x >> y;
		sheep.push_back({x,y});
	}
}

void dfs(int i, int j){
	vs[i][j] = true;
	for(int k = 0; k < 4; k++){
		int i1 = i + dx[k];
		int j1 = j + dy[k];
		if(i1>=1 && i1<=n && j1>=1 && j1<=n && !vs[i1][j1] && !fence.count({{i,j}, {i1,j1}})){
			dfs(i1,j1);
		}
	}
}

void solve(){
	int cnt = 0;
	for(auto x : sheep){
		memset(vs, false, sizeof(vs));
		dfs(x.first, x.second);
		for(pii it : sheep){
			if(!vs[it.first][it.second]){
				cnt++;
			}
		}
	}
	cout << cnt/2 << endl;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	input();
	solve();
	return 0;
}

