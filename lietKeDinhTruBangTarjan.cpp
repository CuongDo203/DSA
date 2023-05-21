#include <bits/stdc++.h>
using namespace std;

int n, m;
int timer = 0;
vector<int> ke[1005];
int disc[1005], low[1005];
bool vs[1005], ap[1005];

void input(){
	memset(ke,0,sizeof(ke));
	memset(vs, false, sizeof(vs));
	memset(ap, false, sizeof(ap));
	memset(disc, 0, sizeof(disc));
	memset(low, 0, sizeof(low));
	timer = 0;
	cin >> n >> m;
	for(int i = 0; i < m; i++){
		int x, y;
		cin >> x >> y;
		ke[x].push_back(y);
		ke[y].push_back(x);
	}	
}

void dfs(int u, int par){
	vs[u] = true;
	low[u] = disc[u] = ++timer;
	int child = 0;
	for(auto v : ke[u]){
		if(v == par) continue;
		if(!vs[v]){
			dfs(v,u);
			child++;
			low[u] = min(low[u], low[v]);
			if(par != -1 && disc[u] <= low[v]){
				ap[u] = true;
			}
		}
		else{
			low[u] = min(low[u], disc[v]);
		}
	}
	if(par == -1 && child > 1){
		ap[u] = true;
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
		for(int i = 1; i <= n; i++){
			if(!vs[i]){
				dfs(i,-1);
			}
		}
		for(int i = 1; i <= n; i++){
			if(ap[i])
				cout << i << " ";
		}
		cout << endl;
	}
	return 0;
}

