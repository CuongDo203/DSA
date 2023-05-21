#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;

int n, m;
int d[1005][1005], a[1005][1005];
bool visited[1005][1005];

int bfs(int i, int j){
	queue<pii> q;
	q.push({i,j});
	d[i][j] = 0;
	visited[i][j] = true;
	while(!q.empty()){
		pii top = q.front();
		q.pop();
		int i1 = top.first;
		int j1 = top.second;
		if(i1 == n && j1 == m) return d[i1][j1]; 
		if(i1 + a[i1][j1] <= n && !visited[i1 + a[i1][j1]][j1]){
			q.push({i1 + a[i1][j1], j1});
			visited[i1 + a[i1][j1]][j1] = true;
			d[i1 + a[i1][j1]][j1] = d[i1][j1] + 1;
		}
		if(j1 + a[i1][j1] <= m && !visited[i1][j1 + a[i1][j1]]){
			q.push({i1, j1 + a[i1][j1]});
			visited[i1][j1 + a[i1][j1]] = true;
			d[i1][j1 + a[i1][j1]] = d[i1][j1] + 1;
		}
	}
	return -1;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while(t--){
		memset(visited, false, sizeof(visited));
		memset(d, 0, sizeof(d));
		cin >> n >> m;
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= m; j++){
				cin >> a[i][j];
			}
		}
		cout << bfs(1,1) << endl;
	} 
	return 0;
}

