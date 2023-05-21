#include <bits/stdc++.h>
using namespace std;

int n, m;
int a[505][505];
bool visited[505][505];
int dx[8] = {-1,-1,-1,0,1,1,1,0};
int dy[8] = {-1,0,1,1,1,0,-1,-1};

void input(){
	memset(a,0,sizeof(a));
	memset(visited, false, sizeof(visited));
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			cin >> a[i][j];
		}
	}
}

void dfs(int i, int j){
	visited[i][j] = true;
	for(int k = 0; k < 8; k++){
		int i1 = i+dx[k];
		int j1 = j+dy[k];
		if(i1>=1 && i1<=n && j1>=1 && j1<=m && a[i1][j1] && !visited[i1][j1]){
			dfs(i1,j1);
		}
	}
}

void solve(){
	memset(visited, false, sizeof(visited));
	int cnt = 0;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			if(a[i][j] && !visited[i][j]){
				cnt++;
				dfs(i,j);
			}
		}
	}
	cout << cnt << endl;
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

