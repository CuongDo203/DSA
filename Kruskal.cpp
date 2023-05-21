#include <bits/stdc++.h>
using namespace std;

struct edge{
	int x, y, w;
};

int n, m;
vector<edge> E;
int p[1005], sz[1005];

void input(){
	E.clear();
	memset(p,0,sizeof(p));
	memset(sz,0,sizeof(sz));
	cin >> n >> m;
	for(int i = 0; i < m; i++){
		int x,y,w;
		cin >> x >> y >> w;
		edge e{x,y,w};
		E.push_back(e);
	} 
	for(int i = 1; i <= n; i++){
		sz[i] = 1;
		p[i] = i;
	}
}

int Find(int u){
	if(u == p[u]) return u;
	else{
		p[u] = Find(p[u]);
		return p[u];
	}
}

bool Union(int u, int v){
	u = Find(u);
	v = Find(v);
	if(u == v) return false;
	if(sz[u] < sz[v]){
		sz[v] += sz[u];
		p[u] = v;
	}
	else{
		sz[u] += sz[v];
		p[v] = u;
	}
	return true;
}

void kruskal(){
	long long d = 0;
	vector<edge> MST;
	sort(E.begin(), E.end(), [](edge a, edge b)->bool{
		return a.w < b.w;
	});	
	for(edge e : E){
		if(MST.size() == n-1) break;
		if(Union(e.x, e.y)){
			d += e.w;
			MST.push_back(e);
		}
	}
	cout << d << endl;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while(t--){
		input();
		kruskal();
	} 
	return 0;
}

