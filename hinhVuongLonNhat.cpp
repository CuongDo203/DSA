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
		cin >> n >> m;
		int a[n][m];
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> a[i][j];
			}
		}
		int dp[n][m];
		for(int i = 0; i < n; i++){
			dp[i][0] = a[i][0];
		}
		for(int i = 0; i < m; i++){
			dp[0][i] = a[0][i];
		}
		for(int i = 1; i < n; i++){
			for(int j = 1; j < m; j++){
				if(a[i][j] == 1){
					dp[i][j] = min({dp[i-1][j-1], dp[i-1][j], dp[i][j-1]}) + 1;
				}
				else{
					dp[i][j] = 0;
				}
			}
		}
		int ans = 0;
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				ans = max(ans, dp[i][j]);
			}
		}
		cout << ans << endl;
	} 
	return 0;
}

