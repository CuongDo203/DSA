#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while(t--){
		int n, k;
		cin >> n >> k;
		int dp[n+5][k];
		dp[0][0] = 0;
		for(int i = 1; i < k; i++){
			dp[0][i] = -1e9;
		}
		for(int i = 1; i <= n; i++){
			int x;
			cin >> x;
			x%=k;
			for(int j = 0; j < k; j++){
				dp[i][j] = max(dp[i-1][j], dp[i-1][(j+k-x)%k] + 1);
			}
		}
		cout << dp[n][0] << endl;
	}
	return 0;
}

