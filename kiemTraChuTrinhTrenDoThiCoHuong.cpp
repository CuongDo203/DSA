#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> ke[1005];
int degree[1005];

void input(){
	memset(ke,0,sizeof(ke));
	memset(degree, 0, sizeof(degree));
	cin >> n >> m;
	for(int i = 0; i < m; i++){
		int x, y;
		cin >> x >> y;
		ke[x].push_back(y);
		degree[y]++;
	}
}

void kahn(){
	queue<int> q;
	for(int i = 1; i <= n; i++){
		if(degree[i]==0){
			q.push(i);
		}
	}
	vector<int> ans;
	while(!q.empty()){
		int u = q.front();
		q.pop();
		ans.push_back(u);
		for(auto v : ke[u]){
			degree[v]--;
			if(degree[v]==0){
				q.push(v);
			}
		}
	}
	if(ans.size() < n){
		cout << "YES\n";
	}
	else{
		cout << "NO\n";
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while(t--){
		input();
		kahn();
	}
	return 0;
}

