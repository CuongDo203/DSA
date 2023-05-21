#include <bits/stdc++.h>
using namespace std;

int n, m;
int a[505][505];
int cost[505][505];

int dx[4] = {-1,0,0,1};
int dy[4] = {0,-1,1,0};

void input(){
	memset(a,0,sizeof(a));
	memset(cost,0,sizeof(cost));
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			cin >> a[i][j];
			cost[i][j] = INT_MAX;
		}
	}
}

void bfs(int i, int j){
	queue<pair<int,int>> q;
	q.push({i,j});
	cost[i][j] = a[i][j];
	while(!q.empty()){
		pair<int,int> top = q.front();
		q.pop();
		for(int k = 0; k < 4; k++){
			int i1 = top.first + dx[k];
			int j1 = top.second + dy[k];
			if(i1 >= 1 && i1 <= n && j1 >= 1 && j1 <= m){
				if(cost[i1][j1] > cost[top.first][top.second] + a[i1][j1]){
					cost[i1][j1] = cost[top.first][top.second] + a[i1][j1];
					q.push({i1,j1});
				}
			}
		}
	}
}

void solve(){
	bfs(1,1);
	cout << cost[n][m] << endl;
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

