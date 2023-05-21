#include <bits/stdc++.h>
using namespace std;

struct edge{
	int x, y, w;
};

vector<edge> v;
int n, m;

void nhap(){
	v.clear();
	cin >> n >> m;
	for(int i = 0; i < m; i++){
		int x, y, w;
		cin >> x >> y >> w;
		edge e{x,y,w};
		v.push_back(e);
	}
}

bool solve(int s){
	vector<int> dist(n+1, 1e9);
	dist[s] = 0;
	for(int i = 0; i < n-1; i++){
		for(auto it : v){
			if(dist[it.x] < 1e9){
				if(dist[it.y] > dist[it.x] + it.w){
					dist[it.y] = dist[it.x] + it.w;
				}
			}
		}
	}
	//for(int i = 0; i < n-1; i++){
		for(auto it : v){
			if(dist[it.x] < 1e9){
				if(dist[it.y] > dist[it.x] + it.w){
					return true;
					dist[it.y] = dist[it.x] + it.w;
				}
			}
		}
	//}
	return false;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while(t--){
		nhap();
		bool ok = false;
		for(int i = 1; i <= n; i++){
			if(solve(i)){
				ok = true;
				break;
			}
		}
		if(ok) cout << "1\n";
		else cout << "0\n";
	}
	return 0;
}

