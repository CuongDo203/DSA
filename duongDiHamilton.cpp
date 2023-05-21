#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> ke[101];
int x[101];
bool visited[101], ok = false;

void input(){
	memset(visited, false, sizeof(visited));
	ok = false;
	memset(x,0,sizeof(x));
	memset(ke,0,sizeof(ke));
	cin >> n >> m;
	for(int i = 0; i < m; i++){
		int x,y;
		cin >> x >> y;
		ke[x].push_back(y);
		ke[y].push_back(x);
	}
}

void hmt(int i, int cnt){
	if(cnt == n){
		ok = true;
		return;
	}
	for(auto it : ke[i]){
		if(!visited[it]){
			visited[it] = true;
			hmt(it, cnt+1);
			visited[it] = false;
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
		input();
		for(int i = 1; i <= n; i++){
			memset(visited, false, sizeof(visited));
			visited[i] = true;
			hmt(i,1);
			if(ok) break;
		}
		if(ok) cout << 1 << endl;
		else cout << 0 << endl;
	}
	return 0;
}

