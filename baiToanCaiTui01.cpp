#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while(t--){
		int n, v;
		cin >> n >> v;
		int a[n+1];
		int c[n+1];
		for(int i = 1; i <= n; i++){
			cin >> a[i];
		}
		for(int i = 1; i <= n; i++){
			cin >> c[i];
		}
		int dp[1005][1005];
		for(int i = 1; i <= n; i++){
			for(int j = 0; j <= v; j++){
				dp[i][j] = dp[i-1][j];
				if(a[i] <= j){
					dp[i][j] = max(dp[i-1][j-a[i]] + c[i], dp[i][j]);
				}
			}
		}
		cout << dp[n][v] << endl;
	}
	return 0;
}

