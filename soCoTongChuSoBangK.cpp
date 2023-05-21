#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9+7;
long long dp[105][50005];
int n, k;

void init(){
	memset(dp, 0, sizeof(dp));
	for(int j = 0; j <= 9; j++){
		dp[1][j] = 1;
	}
	for(int i = 2; i <= 100; i++){
		for(int j = 1; j <= 50000; j++){
			for(int k = 0; k <= 9; k++){
				if(j > k){
					dp[i][j] += dp[i-1][j-k];
					dp[i][j] %= mod;
				}
			}
		}
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	init();
	int t;
	cin >> t;
	while(t--){
		cin >> n >> k;
		cout << dp[n][k] << endl;
	}
	return 0;
}

