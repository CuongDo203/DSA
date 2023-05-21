#include <bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin >> t;
	while(t--){
		int n, m, idx;
		cin >> n >> m >> idx;
		int a[101][101];
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= m; j++){
				cin >> a[i][j];
			}
		}
		priority_queue<int, vector<int>, greater<int>> v;
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= m; j++){
				if(j == idx){
					v.push(a[i][j]);
				}
			}
		}
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= m; j++){
				if(j == idx){
					cout << v.top() << ' ';
					v.pop();
				}
				else{
					cout << a[i][j] << ' ';
				}
			}
			cout << endl;
		}	
	}
	return 0;
}
