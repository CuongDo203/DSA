#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> ke[1005];
bool visited[1005];
int p[1005];

void input(){
	memset(visited, false, sizeof(visited));
	memset(p,0,sizeof(p));
	memset(ke,0,sizeof(ke));
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int x, y;
        cin >> x >> y;
        ke[x].push_back(y);
        ke[y].push_back(x);
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
        else{
            if(v != p[u]){
                return true;  
            }
        }
    }
    return false;
}

void solve(){
	for(int i = 1; i <= n; i++){
		memset(visited, false, sizeof(visited));
        if(dfs(i)){
            cout << "YES\n";
            return;
        }
    }
    cout << "NO\n";
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
