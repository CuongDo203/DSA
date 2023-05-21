#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;

int n, m;
int a[501][501];
bool vs[501][501];

int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

void nhap(){
	memset(vs, false, sizeof(vs));
	cin >> n >> m;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cin >> a[i][j];
		}
	}
}

void bfs(){	
	int ans = 1;
	bool ok = true;
	queue<pair<pii, int>> q;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(a[i][j] == 2){
				q.push({{i,j}, 0});
			}
		}
	}
	while(!q.empty()){
		pii toaDo = q.front().first;
		int day = q.front().second;
		q.pop();
		if(day > ans){
			ans = day;
		}
		for(int k = 0; k < 4; k++){
			int i = toaDo.first + dx[k];
			int j = toaDo.second + dy[k];
			if(i >= 0 && i < n && j >= 0 && j < m && a[i][j] == 1){
				a[i][j] = 2;
				q.push({{i,j}, day+1});
			}
		}
	}
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(a[i][j] == 1){
				ok = false;
				break;
			}
		}
	}
	if(!ok){
		cout << "-1\n";
	}
	else{
		cout << ans << endl;
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

