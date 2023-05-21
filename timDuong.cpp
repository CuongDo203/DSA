#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;

int n, m;
char a[505][505];
bool vs[505][505], ok = false;
pii start, finish;

int dx[4] = {0,-1,0,1};
int dy[4] = {-1,0,1,0};

void input(){
	memset(vs, false, sizeof(vs));
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			cin >> a[i][j];
			if(a[i][j] == 'S'){
				start.first = i;
				start.second = j;
			//	a[i][j] = '.';
			}
			if(a[i][j] == 'T'){
				finish.first = i;
				finish.second = j;
				a[i][j] = '.';
			}
		}
	}
}

bool dfs(int i, int j, int cnt, int pre){
	if(cnt > 2) return 0;
	if(i == finish.first && j == finish.second){
		return 1;
	}
	for(int k = 0; k < 4; k++){
		int i1 = i + dx[k];
		int j1 = j + dy[k];
		if(i1 >= 1 && i1 <= n && j1 >= 1 && j1 <= m && a[i1][j1] == '.' && !vs[i1][j1]){
			vs[i1][j1] = true;
			if(k == pre){
				if(dfs(i1,j1, cnt, k)) return 1;
			}
			else{
				if(dfs(i1,j1, cnt+1, k)) return 1;
			}
			vs[i1][j1] = false;
		}
	}
	return 0;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while(t--){
		input();
		if(dfs(start.first, start.second, -1, -1)) cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}

