#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while(t--){
		int n, m;
		cin >> n >>m;
		int a[n], b[m] = {};
		long long p[n+m-1] = {0};
		for(int i = 0; i < n; i++) {
			cin >> a[i];
		}
		for(int j = 0; j < m; j++){
			cin >> b[j];
		}
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				p[i+j] += a[i]*b[j];
			}
		}
		for(auto x : p){
			cout << x << " ";
		}
		cout << endl;
	}
	return 0;
}

