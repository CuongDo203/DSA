#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;

int n, m, start;
vector<pii> ke[1005];

void input(){
	for(int i = 0; i <= 1005; i++){
		ke[i].clear();
	}
	cin >> n >> m >> start;
	for(int i = 0; i < m; i++){
		int x, y, w;
		cin >> x >> y >> w;
		ke[x].push_back({y,w});
		ke[y].push_back({x,w});
	}
}


void dijkastra(int s){
	vector<int> dist(n+1, 1e9);
	dist[s] = 0;
	priority_queue<pii, vector<pii>, greater<pii>> q;
	q.push({0,s});
	while(!q.empty()){
		pii top = q.top();
		q.pop();
		int kc = top.first, u = top.second;
		if(kc > dist[u]) continue;
		for(auto it : ke[u]){
			int w = it.second, v = it.first;
			if(dist[v] > dist[u] + w){
				dist[v] = dist[u] + w;
				q.push({dist[v], v});
			}
		}
	}
	for(int i = 1; i <= n; i++){
		cout << dist[i] << ' ';	
	}
	cout << endl;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while(t--){
		input();
		dijkastra(start);
	}
	return 0;
}

