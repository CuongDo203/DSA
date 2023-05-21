#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;

int n;
pair<int,int> start, finish;
char c[105][105];
bool vs[105][105];
pair<int,int> path[4] = {{0,1}, {1,0}, {0,-1}, {-1,0}};

void nhap(){
	memset(vs, false, sizeof(vs));
	cin >> n;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cin >> c[i][j];
		}
	}
	cin >> start.first >> start.second >> finish.first >> finish.second;
	c[finish.first][finish.second] = '.';
}

void bfs(){
	queue<pair<pii,int>> q;
	q.push({start, 0});
	vs[start.first][start.second] = true;
	while(!q.empty()){
		pii toaDo = q.front().first;
		int step = q.front().second;
		q.pop();
		int i = toaDo.first;
		int j = toaDo.second;
		//cout << i << " " << j << " " << step << endl;
		if(i == finish.first && j == finish.second){
			cout << step << endl;
			return;
		}
		for(int k = 0; k < 4; k++){
			int x = path[k].first;
			int y = path[k].second;
			int i1 = i, j1 = j;
			while(!vs[i1+x][j1+y] && c[i1+x][j1+y] == '.' && i1+x >= 0 && i1+x < n && j1+y >= 0 && j1+y < n){ 
				i1 += x;
				j1 += y;
				vs[i1][j1] = true;
				q.push({{i1,j1}, step+1});
			}
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
		nhap();
		bfs();
	} 
	return 0;
}

