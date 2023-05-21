#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;

int n, m, start;
vector<int> ke[1005];
bool vs[1005];
vector<pii> res;

void input(){
	res.clear();
	memset(vs, false, sizeof(vs));
	memset(ke,0,sizeof(ke));
	cin >> n >> m >> start;
	for(int i = 0; i < m; i++){
		int x, y;
		cin >> x >> y;
		ke[x].push_back(y);
		ke[y].push_back(x);
	}
}

void dfs(int u){
	vs[u] = true;
	for(auto v : ke[u]){
		if(!vs[v]){
			res.push_back({u,v});
			dfs(v);
		}
	}
}

void solve(){
	dfs(start);
	if(res.size() != n-1){
		cout << "-1\n";
		return;
	}
	for(int i = 1; i <= n; i++){
		if(!vs[i]){
			cout << "-1\n";
			return;
		}
	}
	for(auto x : res){
		cout << x.first << " " << x.second << endl;
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

