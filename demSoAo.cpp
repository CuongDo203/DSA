#include <bits/stdc++.h>
using namespace std;

int n, m;
char a[1005][1005];
bool visited[1005][1005];
int dx[8] = {-1,-1,-1,0,1,1,1,0};
int dy[8] = {-1,0,1,1,1,0,-1,-1};

void input(){
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
		if(i1 >= 1 && i1 <= n && j1 >= 1 && j1 <= m && a[i1][j1] == 'W' && !visited[i1][j1]){
			dfs(i1,j1);
		}
	}
}

void solve(){
	int cnt = 0;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			if(a[i][j] == 'W' && !visited[i][j]){
				dfs(i,j);
				cnt++;
			}
		}
	}
	cout << cnt << endl;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	input();
	solve();
	return 0;
}

