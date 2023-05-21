#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9+7;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		int dp[101][10];
		memset(dp,0,sizeof(dp));
		for(int j = 0; j <= 9; j++){
			dp[1][j] = 1;
		} 
		for(int i = 2; i <= 100; i++){
			for(int j = 0; j <= 9; j++){
				for(int k = j; k <= 9; k++){
					dp[i][j] += dp[i-1][k];
					dp[i][j] %= mod;
				}
			}
		}
		long long ans = 0;
		for(int j = 0; j <= 9; j++){
			ans += dp[n][j];
			ans %= mod;
		} 
		cout << ans << endl;
	}
	return 0;
}

