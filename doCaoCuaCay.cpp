#include <bits/stdc++.h>
using namespace std;

vector<int> ke[100005]; 
bool vs[100005];

int res;

void dfs(int u, int cnt){
	res = max(res, cnt);
	vs[u] = true;
	for(auto v: ke[u]){
		if(!vs[v]){
			dfs(v, cnt+1);				
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
		memset(vs, false, sizeof(vs));
		memset(ke,0, sizeof(ke));
		int n;
		cin >> n;
		for(int i = 0; i < n-1; i++){
			int x, y;
			cin >> x >> y;
			ke[x].push_back(y);
		}
		res= 0;
		dfs(1, 0);
		cout << res << endl;
	}	
	return 0;
}

