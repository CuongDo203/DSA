#include <bits/stdc++.h>
using namespace std;

int n,m, mau;
vector<int> ke[1001];
int color[1001];

int res;

void dfs(int u){
	vector<bool> alreadyAssigned(n,false);
	for(auto x : ke[u]){
		alreadyAssigned[color[x]] = true;
	}
	int c;
	for(c = 1; c <= n; c++){
		if(!alreadyAssigned[c]){
			break;
		}
	}
	color[u] = c;
	res = max(res, c);
	sort(ke[u].begin(), ke[u].end(), [](int x, int y)->bool{
		return ke[x].size() >= ke[y].size();
	});
	for(auto it : ke[u]){
		if(!color[it])
			dfs(it);
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while(t--){
		memset(ke,0,sizeof(ke));
		memset(color, 0,sizeof(color));
		cin >> n >> m >> mau;
		for(int i = 0; i < m; i++){
			int x,y;
			cin >> x >> y;
			ke[x].push_back(y);
			ke[y].push_back(x);
		}
		res = 0;
		for(int i = 1; i <= n; i++){
			if(!color[i]){
				dfs(i);
			}
		}
		if(res > mau) cout << "NO\n";
		else cout << "YES\n";
	}
	return 0;
}
