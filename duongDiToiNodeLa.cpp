#include <bits/stdc++.h>
using namespace std;

vector<int> ke[1005];
bool vs[1005];
int p[1005];
vector<int> leaf;

void dfs(int u){
	vs[u] = true;
	for(int v : ke[u]){
		if(!vs[v]){
			p[v] = u;
			dfs(v);
		}
	}
}

void findPath(int u, int &v){
	vector<int> path;
	while(v != u){
		path.push_back(v);
		v = p[v];
	}
	path.push_back(u);
	for(int i = path.size()-1; i >= 0; i--){
		cout << path[i] << " ";
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while(t--){
		memset(ke, 0, sizeof(ke));
		memset(vs, false, sizeof(vs));
		int n;
		cin >> n;
		for(int i = 0; i < n-1; i++){
			int x, y;
			cin >> x >> y;
			ke[x].push_back(y);
		}
		leaf.clear();
		for(int i = 1; i <= n; i++){
			if(ke[i].size() == 0){
				leaf.push_back(i);
			}
		}
		for(int x : leaf){
			memset(vs, false, sizeof(vs));
			memset(p, 0, sizeof(p));
			dfs(1);
			findPath(1, x);
			cout << endl;			
		}
	}
	return 0;
}

