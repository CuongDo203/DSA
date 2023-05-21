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
		int n, k;
		cin >> n >> k;
		long long dp[n+1];
		memset(dp,0,sizeof(dp));
		dp[0] = 1;
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= min(i, k); j++){
				dp[i] += dp[i-j];
				dp[i] %= mod;
			}
		}
		cout << dp[n] << endl;
	}	
	return 0;
}

