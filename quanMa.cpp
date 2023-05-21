#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

int s, t, u, v; 
bool visited[1005][1005];
int d[1005][1005];

int dx[8] = {-1,-2,-2,-1,1,2,2,1};
int dy[8] = {-2,-1,1,2,2,1,-1,-2};

int solve(int i, int j){
	queue<pii> q;
	q.push({i,j});
	visited[i][j] = true;
	d[i][j] = 0;
	while(!q.empty()){
		pii top = q.front();
		q.pop();
		if(top.first == u && top.second == v) return d[top.first][top.second];
		for(int k = 0; k < 8; k++){
			int i1 = top.first + dx[k];
			int j1 = top.second + dy[k];
			if(i1 >= 1 && i1 <= 8 && j1 >= 1 && j1 <= 8 && !visited[i1][j1]){
				d[i1][j1] = d[top.first][top.second] + 1;
				q.push({i1,j1});
				visited[i1][j1] = true;
			}
		}
	}
	return -1;
}


int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int test;
	cin >> test;
	while(test--){
		memset(visited, false, sizeof(visited));
		memset(d,0,sizeof(d));
		string a, b;
		cin >> a >> b;
		s = a[0] - 'a' + 1;
		t = a[1] - '0';
		u = b[0] - 'a' + 1;
		v = b[1] - '0';
		cout << solve(s,t) << endl;
	}
	return 0;
}

