#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> ke[1005];


int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while(t--){
		cin >> n >> m;
		for(int i = 1; i <= m; i++){
			int x, y;
			cin >> x >> y;
			ke[x].push_back(y);
		}
		for(int i = 1; i <= n; i++){
			cout << i << ": ";
			for(auto x : ke[i]){
				cout << x << " ";
			}
			cout << endl;
		}
		for(int i = 0; i <= 1005; i++){
			ke[i].clear();
		} 
	}
	return 0;
}

