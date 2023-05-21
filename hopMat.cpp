#include <bits/stdc++.h>
using namespace std;

int k, n, m;
int pos[1005], cnt[1005];
vector<int> ke[1005];
bool vs[1005];

void input(){
	cin >> k >> n >> m;
	for(int i = 0; i < k; i++){
		cin >> pos[i];
	}
	for(int i = 0; i < m; i++){
		int x, y;
		cin >> x >> y;
		ke[x].push_back(y);
	}
}

void bfs(int u){
	vs[u] = true;
	cnt[u]++;
	queue<int> q;
	q.push(u);
	while(!q.empty()){
		int v = q.front();
		q.pop();
		for(int x : ke[v]){
			if(!vs[x]){
				q.push(x);
				vs[x] = true;
				cnt[x]++;
			}
		}
	}
}

void solve(){
	for(int i = 0; i < k; i++){
		memset(vs,false,sizeof(vs));
		bfs(pos[i]);
	} 
	int dem = 0;
	for(int i = 1; i <= n; i++){
		if(cnt[i] == k){
			dem++;
		}
	}
	cout << dem << endl;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	input();
	solve();
	return 0;
}

