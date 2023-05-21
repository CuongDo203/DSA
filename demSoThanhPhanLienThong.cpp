#include <bits/stdc++.h>
using namespace std;

int n, m;  
vector<int> ke[1005];
bool visited[1005];

void dfs(int u){
    visited[u] = true;
    for(auto v : ke[u]){
        if(!visited[v]){
            dfs(v);
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
		memset(visited, false, sizeof(visited));
		cin >> n >> m;
	    for(int i = 0; i < m; i++){
	        int x, y;
	        cin >> x >> y;
	        ke[x].push_back(y);
	        ke[y].push_back(x);
	    }
	    int cnt = 0;
	    for(int i = 1; i <= n; i++){
	        if(!visited[i]){
	            dfs(i);
	            cnt++;
	        }
	    }
	    cout << cnt << endl;
	    memset(ke,0,sizeof(ke));
	}
	return 0;
}

