#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> ke[1005];
bool visited[1005];
int p[1005];
vector<int> res;

void input(){
	memset(ke,0,sizeof(ke));
	memset(visited, false, sizeof(visited));
	memset(p,0,sizeof(p));
	res.clear();
	cin >> n >> m;
	for(int i = 0; i < m; i++){
		int x, y;
		cin >> x >> y;
		ke[x].push_back(y);
		ke[y].push_back(x);
	}
	for(int i = 1; i <= n; i++){
		sort(ke[i].begin(), ke[i].end());
	}
}

bool dfs(int u){
	visited[u] = true;
	for(int v : ke[u]){
		if(!visited[v]){
			p[v] = u;
			if(dfs(v))
				return true;
		}
		else if(v==1){
			if(v != p[u]){
				res.push_back(u);
				while(u != v){
					u = p[u];
					res.push_back(u);
				}
				return true;
			}
		}
	}
	return false;
}

void solve(){
	
	if(dfs(1)){
		if(res.back() != 1){
			cout << "NO\n";
			return;
		}
		
		reverse(res.begin(), res.end());
		for(auto x : res){
			cout << x << " ";
		}
		cout << "1 ";
		cout << endl;
	}
	else{
		cout << "NO\n";
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
