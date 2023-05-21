#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> ke[1005];
bool vs[1005];

void input(){
	memset(vs,0,sizeof(vs));
	memset(ke,0,sizeof(ke));
	cin >> n;
	for(int i = 1; i < n; i++){
		int x, y;
		cin >> x >> y;
		ke[x].push_back(y);
		ke[y].push_back(x);
	}
}

void bfs(int u){
	vs[u] = true;
	queue<int> q;
	q.push(u);
	while(!q.empty()){
		int v = q.front();
		q.pop();
		for(auto x : ke[v]){
			if(!vs[x]){
				vs[x] = true;
				q.push(x);
			}
		}
	}
}

void solve(){
	bfs(1);
	for(int i = 2; i <= n; i++){
		if(!vs[i]){
			cout << "NO\n";
			return;
		}
	}
	cout << "YES\n";
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

