#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> ke[1005];
bool vs[1005];
int deg[1005];

void input(){
	memset(vs, false, sizeof(vs));
	memset(ke,0,sizeof(ke));
	memset(deg,0,sizeof(deg));
	cin >> n >> m;
	for(int i = 0; i < m; i++){
		int x, y;
		cin >> x >> y;
		ke[x].push_back(y);
		ke[y].push_back(x);
		deg[x]++;
		deg[y]++;
	}
}

void dfs(int u){
	vs[u] = true;
	for(int v : ke[u]){
		if(!vs[v]){
			dfs(v);
		}
	}
}

bool isConnected(){
	memset(vs, false, sizeof(vs));
	dfs(1);
	for(int i = 2; i <= n; i++){
		if(!vs[i]){
			return false;
		}
	}
	return true;
}

void solve(){
	int cnt = 0;
	for(int i = 1; i <= n; i++){
		if(deg[i]%2==1){
			cnt++;
		}
	}
	if(cnt == 0 && isConnected()){
		cout << 2 << endl;
	}
	else if(cnt == 2){
		cout << 1 << endl;
	}
	else{
		cout << 0 << endl;
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

